/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_uninitialized_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:01:50 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:05:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strlen_uninitialized_test(void)
{
	char	*str;

	if (strlen((char *)0x123456789) == 0)
		return (0);
	else
		return (-1);
}
