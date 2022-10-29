/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intmax_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:38:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 21:59:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
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

int	cvrt_u_intmax_test(void)
{
	t_data	d;
	int		cmp;

	memset(&d, 0, sizeof(t_data));
	if (redirect_init())
		return (EXIT_FAILURE);
	d.ret0 = printf("Easy%u !", INT_MAX);
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
	d.ret1 = ft_printf("Easy%u !", INT_MAX);
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
