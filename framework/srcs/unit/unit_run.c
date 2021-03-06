/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 19:17:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "internal_functions.h"
#include "unit.h"
#include "t_unit.h"

static void	__timer_handler(int const sig __attribute__((unused)))
{
	exit(-2);
}

static void	__init_timeout_handler(void)
{
	struct sigaction	act;
	struct timeval		interval;
	struct itimerval	period;
	sigset_t			block ;

	sigemptyset(&block);
	sigaddset(&block, SIGVTALRM);
	bzero(&act, sizeof(act));
	act.sa_handler = __timer_handler;
	if (sigaction(SIGVTALRM, &act, NULL))
		exit(EXIT_FAILURE);
	interval.tv_sec = TIMEOUT_VALUE;
	interval.tv_usec = 0;
	period.it_interval = interval;
	period.it_value = interval;
	setitimer(ITIMER_VIRTUAL, &period, NULL);
}

static void	__execute_tests(t_unit *const node)
{
	t_fct	call;
	int		status;

	call = node->call;
	output_name(node->funcname, node->testname, STDOUT_FILENO);
	unit_clear(node);
	__init_timeout_handler();
	status = call();
	exit(status);
}

static int	__translate_status(int raw_status)
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
	int		status;

	worker = fork();
	if (worker == -1 || write(STDOUT_FILENO, "", 0) == -1)
		return (EXIT_FAILURE);
	if (!worker)
		__execute_tests(node);
	if (wait(&status) == -1)
		return (EXIT_FAILURE);
	status = __translate_status(status);
	return (output_status(status, STDOUT_FILENO));
}
