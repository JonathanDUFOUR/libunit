/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 08:13:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 22:33:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	*__pipe(void)
{
	static int	new_pipe[2] = {-1, -1};

	return (new_pipe);
}

static int	*__stdin(void)
{
	static int	fd = -1;

	return (&fd);
}

static int	*__stdout(void)
{
	static int	fd = -1;

	return (&fd);
}

/*
	Open a pipe between STDIN_FILENO and STDOUT_FILENO
	+
	Keep a copy of the original stdin and stdout to restore them later
*/
int	redirect_init(void)
{
	*__stdin() = dup(STDIN_FILENO);
	*__stdout() = dup(STDOUT_FILENO);
	if (pipe(__pipe()) == -1)
		return (EXIT_FAILURE);
	if (close(STDIN_FILENO) || close(STDOUT_FILENO)
		|| *__stdin() == -1 || *__stdout() == -1
		|| dup2(__pipe()[0], STDIN_FILENO) == -1
		|| dup2(__pipe()[1], STDOUT_FILENO) == -1)
	{
		if (*__stdin() != -1)
			close(*__stdin());
		if (*__stdout() != -1)
			close(*__stdout());
		close(__pipe()[0]);
		close(__pipe()[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
	Close the previously opened pipe, and restore stdin and atdout
*/
int	redirect_end(void)
{
	if ((__pipe()[0] != -1 && close(__pipe()[0]))
		|| (__pipe()[1] != -1 && close(__pipe()[1]))
		|| (*__stdin() != -1
			&& (dup2(*__stdin(), STDIN_FILENO) == -1 || close(*__stdin())))
		|| (*__stdout() != -1
			&& (dup2(*__stdout(), STDOUT_FILENO) == -1 || close(*__stdout()))))
	{
		*__stdin() = -1;
		*__stdout() = -1;
		return (EXIT_FAILURE);
	}
	*__stdin() = -1;
	*__stdout() = -1;
	return (EXIT_SUCCESS);
}
