/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_pipe_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:02:59 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 15:15:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	write_pipe_test(void)
{
	int	new_pipe[2];

	if (pipe(new_pipe) == -1)
		return (EXIT_FAILURE);
	if (close(new_pipe[0])
		|| write(new_pipe[1], "FooBar", 6) == -1
		|| close(new_pipe[1]))
		return (EXIT_FAILURE);
	return (0);
}
