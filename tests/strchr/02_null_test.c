/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:11:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:54:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strchr_null_test(void)
{
	char	*str;
	char	c;

	str = NULL;
	c = 0;
	if (strchr(str, c) == NULL)
		return (0);
	else
		return (-1);
}
