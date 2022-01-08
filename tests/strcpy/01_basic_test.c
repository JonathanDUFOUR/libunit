/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:01:17 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:03:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strcpy_basic_test(void)
{
	char	dst[14];
	char	src[] = "Hello World !";

	if (strcpy(dst, src) == dst && !strcmp(src, dst))
		return (0);
	else
		return (-1);
}
