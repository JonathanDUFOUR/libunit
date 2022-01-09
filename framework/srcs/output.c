/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 15:10:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lookup_result.h"

static size_t	__len(char const *str)
{
	char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}

void	output_name(char const *funcname, char const *testname)
{
	write(STDOUT_FILENO, "\t", 1);
	write(STDOUT_FILENO, funcname, __len(funcname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, testname, __len(testname));
	write(STDOUT_FILENO, ": ", 2);
}

int	output_status(int const status)
{
	int	i;

	i = 0;
	while (g_result[i].msg && status != g_result[i].status)
		++i;
	if (!g_result[i].msg)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, g_result[i].msg, __len(g_result[i].msg));
	write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
