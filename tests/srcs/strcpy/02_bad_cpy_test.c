/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_bad_cpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:03:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 10:43:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strcpy_bad_cpy_test(void)
{
	char		dst[42];
	char const	src[] = "poneyvif";

	if (strcpy(dst, "pouic") == dst && !strcmp(dst, src))
		return (0);
	else
		return (-1);
}
