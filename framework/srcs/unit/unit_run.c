/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:18:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "t_unit.h"
#include "lookup_result.h"

static size_t	__len(char const *str)
{
	char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}

static int	__output(char const *funcname, char const *testname,
	int const status)
{
	int	i;

	i = 0;
	while (g_result[i].msg && status != g_result[i].status)
		++i;
	if (!g_result[i].msg || write(STDOUT_FILENO, "", 0) == -1)
		return (EXIT_FAILURE);
	write(STDOUT_FILENO, "\t", 1);
	write(STDOUT_FILENO, funcname, __len(funcname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, testname, __len(testname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, g_result[i].msg, __len(g_result[i].msg));
	write(STDOUT_FILENO, "\n", 1);
	return (-!!status);
}

/*
	Run the function contained in the given unit `node` in a child process
	Output the name of function, followed by the name of the current test and
	the exit_status of the test once it is done
*/
int	unit_run(t_unit *const node)
{
	pid_t	child;
	int		status;

	status = 0;
	child = fork();
	if (child == -1)
		return (EXIT_FAILURE);
	if (!child)
	{
		unit_clear(node);
		status = node->call();
		free((void *)node);
		exit(status);
	}
	if (wait(&status) == -1)
		return (EXIT_FAILURE);
	if (WIFEXITED(status))
		status = (char)WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status);
	return (__output(node->funcname, node->testname, status));
}
