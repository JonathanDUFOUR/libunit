/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_medium_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:25:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 21:57:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "unit.h"
#include "ft_printf.h"

typedef struct s_data	t_data;

struct s_data
{
	char		buff[4097];
	char		*str0;
	char		*str1;
	void		*ent;
	int			ret0;
	int			ret1;
	size_t		len;
	ssize_t		rd;
};

int	cvrt_s_medium_test(void)
{
	t_data	d;
	int		cmp;

	memset(&d, 0, sizeof(t_data));
	if (redirect_init())
		return (EXIT_FAILURE);
	d.ret0 = printf("__%s++", "\
tutu bar minato tutu lol troll troll tutu lol foo pouic minato pouic minato lol\
 muf pouic bar muf bar minato lol lol troll muf troll bar pouic pouic bing mina\
to tutu minato bing minato minato google lol google minato google minato muf mi\
nato koala google pouic pouic bing troll troll lol koala pouic koala google goo\
gle minato google bing google muf bar tutu troll muf google muf pouic google go\
ogle lol tutu google bing pouic tutu bar bar troll muf muf bing tutu troll bar \
minato minato minato minato minato minato troll google bing tutu tutu tutu goog\
le lol google koala lol google tutu minato troll minato bing koala koala minato\
 muf minato google google minato koala bing foo bing troll muf bing bar minato \
tutu foo tutu muf minato google minato lol pouic google minato troll troll koal\
a bar troll koala tutu bing google pouic bing bing koala koala bar troll koala \
muf tutu koala minato minato foo koala minato koala google troll muf google min\
ato bing bing troll google minato google minato troll bing koala lol lol go");
	fflush(stdout);
	if (d.ret0 > 0)
		d.rd = read(STDIN_FILENO, d.buff, 4096);
	while (d.rd)
	{
		if (d.str0)
			d.len = strlen(d.str0);
		else
			d.len = 0;
		d.buff[d.rd] = 0;
		d.ent = (void *)d.str0;
		d.str0 = calloc((d.len + strlen(d.buff) + 1), sizeof(char));
		if (!d.str0)
		{
			free(d.ent);
			return (EXIT_FAILURE);
		}
		if (d.len)
			strcpy(d.str0, d.ent);
		free(d.ent);
		strcat(d.str0, d.buff);
		if (d.rd == 4096)
			d.rd = read(STDIN_FILENO, d.buff, 4096);
		else
			d.rd = 0;
	}
	d.ret1 = ft_printf("__%s++", "\
tutu bar minato tutu lol troll troll tutu lol foo pouic minato pouic minato lol\
 muf pouic bar muf bar minato lol lol troll muf troll bar pouic pouic bing mina\
to tutu minato bing minato minato google lol google minato google minato muf mi\
nato koala google pouic pouic bing troll troll lol koala pouic koala google goo\
gle minato google bing google muf bar tutu troll muf google muf pouic google go\
ogle lol tutu google bing pouic tutu bar bar troll muf muf bing tutu troll bar \
minato minato minato minato minato minato troll google bing tutu tutu tutu goog\
le lol google koala lol google tutu minato troll minato bing koala koala minato\
 muf minato google google minato koala bing foo bing troll muf bing bar minato \
tutu foo tutu muf minato google minato lol pouic google minato troll troll koal\
a bar troll koala tutu bing google pouic bing bing koala koala bar troll koala \
muf tutu koala minato minato foo koala minato koala google troll muf google min\
ato bing bing troll google minato google minato troll bing koala lol lol go");
	if (d.ret1 > 0)
		d.rd = read(STDIN_FILENO, d.buff, 4096);
	while (d.rd)
	{
		if (d.str1)
			d.len = strlen(d.str1);
		else
			d.len = 0;
		d.buff[d.rd] = 0;
		d.ent = (void *)d.str1;
		d.str1 = calloc((d.len + strlen(d.buff) + 1), sizeof(char));
		if (!d.str1)
		{
			free(d.ent);
			return (EXIT_FAILURE);
		}
		if (d.len)
			strcpy(d.str1, d.ent);
		free(d.ent);
		strcat(d.str1, d.buff);
		if (d.rd == 4096)
			d.rd = read(STDIN_FILENO, d.buff, 4096);
		else
			d.rd = 0;
	}
	if (d.ret0 > 0 && d.ret1 > 0)
		cmp = strcmp(d.str0, d.str1);
	else
		cmp = 0;
	free(d.str0);
	free(d.str1);
	if (redirect_end())
		return (EXIT_FAILURE);
	if (!cmp && d.ret0 == d.ret1)
		return (0);
	else
		return (-1);
}
