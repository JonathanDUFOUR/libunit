/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 23:12:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lookup_result.h"
#include "internal_functions.h"
#include <fcntl.h>

static size_t	__len(char const *str)
{
	char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}

void	output_name(char const *funcname, char const *testname, int const fd)
{
	write(fd, "\t", 1);
	write(fd, funcname, __len(funcname));
	write(fd, ": ", 2);
	write(fd, testname, __len(testname));
	write(fd, ": ", 2);
}

int	output_status(int const status, int const fd)
{
	int	i;

	i = 0;
	while (g_result[i].msg && status != g_result[i].status)
		++i;
	if (!g_result[i].msg)
		return (EXIT_FAILURE);
	write(fd, g_result[i].msg, __len(g_result[i].msg));
	write(fd, "\n", 1);
	return (status);
}

void	output_check(size_t const successful_test_count,
size_t const total_test_count, int const fd)
{
	putsize(successful_test_count);
	write(fd, "/", 1);
	putsize(total_test_count);
	write(fd, " tests checked\n", 15);
}

int	output_to_logfile(char const *logfile_name)
{
	int	logfile_fd;

	logfile_fd = open(logfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (logfile_fd == -1)
		return (EXIT_FAILURE);
	if (dup2(logfile_fd, STDOUT_FILENO) == -1)
	{
		close(logfile_fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
