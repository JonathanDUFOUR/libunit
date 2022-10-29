/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_uninitialized_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:01:50 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:54:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strlen_uninitialized_test(void)
{
	char	*str;

	if (strlen(str) == 0)
		return (0);
	else
		return (-1);
}
