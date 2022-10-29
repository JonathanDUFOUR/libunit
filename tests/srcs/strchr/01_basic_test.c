/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:10:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:19:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strchr_basic_test(void)
{
	char const	str[] = "test";

	if (strchr(str, 's') == str + 2)
		return (0);
	else
		return (-1);
}
