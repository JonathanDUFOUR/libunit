/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:01:44 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 09:19:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putsize(size_t const nb)
{
	char	d;

	if (nb > 9)
		putsize(nb / 10);
	d = (char)(nb % 10) + '0';
	write(STDOUT_FILENO, &d, 1);
}
