/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:16:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 09:17:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "unit.h"

void	ratio(size_t const checked, size_t const total)
{
	putsize(checked);
	write(STDOUT_FILENO, "/", 1);
	putsize(total);
	write(STDOUT_FILENO, " functions checked\n", 19);
}
