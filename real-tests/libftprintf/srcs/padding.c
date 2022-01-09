/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:10:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 16:51:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "enum/e_ret.h"

int	padding(int const c, int padlen)
{
	char	*padding;
	char	*ptr;

	padding = malloc((padlen + 1) * sizeof(char));
	if (!padding)
		return (MALLOC_ERR);
	ptr = padding;
	while (padlen--)
		*ptr++ = c;
	*ptr = 0;
	write(1, padding, ptr - padding);
	free(padding);
	return (SUCCESS);
}
