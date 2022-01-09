/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_endless_loop_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:46:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 17:33:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	strlen_endless_loop_test(void)
{
	while (strlen("toto"))
		continue ;
	if (strlen("toto") == 4)
		return (0);
	else
		return (-1);
}
