/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:11:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:49:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strlen_null_test(void)
{
	char	*str;

	str = NULL;
	if (strlen(str) == 0)
		return (0);
	else
		return (-1);
}
