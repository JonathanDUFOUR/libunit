/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:11:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 07:14:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strchr_null_test(void)
{
	char	str[] = NULL;
	char	c;
	char	*res_exp;
	char	*res_act;

	c = 's';
	res_exp = NULL;

	res_act = strchr(str, c);
	
	if (res_exp == res_act)
		return (0);
	else
		return (-1);
}