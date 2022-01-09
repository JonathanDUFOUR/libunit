/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 15:48:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "unit.h"
#include "t_unit.h"
#include "internal_functions.h"

static void	__execute_watchdog(void)
{
	sleep(TIMEOUT_VALUE);
	exit(-2);
}

static void	__execute_tests(t_unit *const node)
{
	t_fct	call;
	int		status;

	call = node->call;
	output_name(node->funcname, node->testname);
	unit_clear(node);
	status = call();
	exit(status);
}

static int	__translate_signal(int raw_status)
{
	if (WIFEXITED(raw_status))
		return ((char)WEXITSTATUS(raw_status));
	else if (WIFSIGNALED(raw_status))
		return (WTERMSIG(raw_status));
	return (raw_status);
}

/*
	Run the function contained in the given unit `node` in a child process
	Output the name of function, followed by the name of the current test and
	the exit_status of the test once it is done
*/
int	unit_run(t_unit *const node)
{
	pid_t	worker;
	pid_t	watchdog;
	int		status;

	worker = fork();
	if (worker == -1 || write(STDOUT_FILENO, "", 0) == -1)
		return (EXIT_FAILURE);
	if (!worker)
		__execute_tests(node);
	watchdog = fork();
	if (!watchdog)
		__execute_watchdog();
	if (wait(&status) == -1 || wait(NULL) == -1)
		return (EXIT_FAILURE);
	status = __translate_signal(status);
	return (output_status(status));
}
