/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:10:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 12:21:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "unit.h"

int	write_basic_test(void)
{
	char	buff[4097];
	ssize_t	rd;

	if (redirect_init()
		|| write(STDOUT_FILENO, "test", 4) == -1)
		return (EXIT_FAILURE);
	rd = read(STDIN_FILENO, buff, 4096);
	if (redirect_end())
		return (EXIT_FAILURE);
	if (rd == -1)
		return (EXIT_FAILURE);
	buff[rd] = 0;
	if (!strcmp(buff, "test"))
		return (0);
	else
		return (-1);
}
