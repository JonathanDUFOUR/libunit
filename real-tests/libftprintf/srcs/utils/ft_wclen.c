/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:00:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/10 17:55:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_wclen(wchar_t const wc)
{
	int	len;

	len = 1;
	if (wc >= 0x80 && ++len && wc >= 0x800 && ++len && wc >= 0x10000)
		++len;
	return (len);
}
