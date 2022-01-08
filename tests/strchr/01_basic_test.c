/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:10:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 07:14:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strchr_basic_test(void)
{
	char	*str;
	char	c;
	char	*res_exp;
	char	*res_act;

	str = "test";
	c = 's';
	res_exp = &str[2];

	res_act = NULL;
	///res_act = (char *) 1;//strchr(str, c);
	if (res_exp == res_act)
		return (EXIT_SUCCESS);
	else
		return (-1);
}
