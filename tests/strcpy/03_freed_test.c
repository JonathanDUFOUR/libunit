/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_freed_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:10:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:58:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strcpy_freed_test(void)
{
	char	dst[42];
	char	*src;

	src = malloc(15);
	if (!src)
		return (EXIT_FAILURE);
	free(src);
	if (strcpy(dst, src + 42) == dst && !strcmp(src + 42, dst))
		return (0);
	else
		return (-1);
}
