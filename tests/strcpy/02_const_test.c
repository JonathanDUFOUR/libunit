/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_const_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:03:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:17:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strcpy_const_test(void)
{
	char	*dst = "Lolipop";
	if (strcpy(dst, "pouic") == dst)
		return (0);
	else
		return (-1);
}
