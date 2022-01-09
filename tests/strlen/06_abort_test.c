/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_abort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:46:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 09:17:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strlen_abort_test(void)
{
	abort();
	if (strlen("Pouic") == 5)
		return (0);
	else
		return (-1);
}
