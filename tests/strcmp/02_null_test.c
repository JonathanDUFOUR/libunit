/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:11:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 10:40:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strcmp_null_test(void)
{
	char const	*str = NULL;

	if (!strcmp(str, str))
		return (0);
	else
		return (-1);
}
