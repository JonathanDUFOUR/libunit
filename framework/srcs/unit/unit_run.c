/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 13:11:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "unit.h"
#include "t_unit.h"
#include "lookup_result.h"

static size_t	__len(char const *str)
{
	char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}

static void	__output_name(char const *funcname, char const *testname)
{
	write(STDOUT_FILENO, "\t", 1);
	write(STDOUT_FILENO, funcname, __len(funcname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, testname, __len(testname));
	write(STDOUT_FILENO, ": ", 2);
}

static int	__output_status(int const status)
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

/*
	Run the function contained in the given unit `node` in a child process
	Output the name of function, followed by the name of the current test and
	the exit_status of the test once it is done
*/
int	unit_run(t_unit *const node)
{
	pid_t	child;
	t_fct	call;
	int		status;

	status = 0;
	child = fork();
	if (child == -1 || write(STDOUT_FILENO, "", 0) == -1)
		return (EXIT_FAILURE);
	if (!child)
	{
		call = node->call;
		__output_name(node->funcname, node->testname);
		unit_clear(node);
		status = call();
		exit(status);
	}
	if (wait(&status) == -1)
		return (EXIT_FAILURE);
	if (WIFEXITED(status))
		status = (char)WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status);
	return (__output_status(status));
}
