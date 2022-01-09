/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 18:58:53 by                  ###   ########.fr       */
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

void	output_name(char const *funcname, char const *testname, int fd)
{
	write(fd, "\t", 1);
	write(fd, funcname, __len(funcname));
	write(fd, ": ", 2);
	write(fd, testname, __len(testname));
	write(fd, ": ", 2);
}

int	output_status(int const status, int fd)
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

void	output_check(size_t successful_test_count,
			size_t total_test_count, int fd)
{
	putsize(successful_test_count);
	write(fd, "/", 1);
	putsize(total_test_count);
	write(fd, " tests checked\n", 15);
}

int	redirect_std_out_to_log(char const **av)
{
	int	log_file_fd;

	log_file_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (log_file_fd == -1)
		return (EXIT_FAILURE);
	if (dup2(log_file_fd, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
