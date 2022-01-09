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
#include <sys/types.h>
#include <sys/wait.h>
#include "t_unit.h"
#include "internal_functions.h"

int		translate_signal(int raw_status);
void	execute_tests(t_unit *const node);
void	execute_watchdog(void);

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
	watchdog = -1;
	if (worker == -1 || write(STDOUT_FILENO, "", 0) == -1)
		return (EXIT_FAILURE);
	if (! worker)
		execute_tests(node);
	else
		watchdog = fork();
	if (! watchdog)
		execute_watchdog();
	if (wait(&status) == -1)
		return (EXIT_FAILURE);
	status = translate_signal(status);
	return (output_status(status));
}

void	execute_watchdog(void)
{
	sleep(1);
	exit(-2);
}

void	execute_tests(t_unit *const node)
{
	t_fct	call;
	int		status;

	call = node->call;
	output_name(node->funcname, node->testname);
	unit_clear(node);
	status = call();
	exit(status);
}

int	translate_signal(int raw_status)
{
	if (WIFEXITED(raw_status))
		raw_status = (char)WEXITSTATUS(raw_status);
	else if (WIFSIGNALED(raw_status))
		raw_status = WTERMSIG(raw_status);
	return (raw_status);
}
