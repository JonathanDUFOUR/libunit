/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_abort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:46:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 14:39:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	timeout_test(void)
{
	sleep(10);
	return (EXIT_SUCCESS);
}
