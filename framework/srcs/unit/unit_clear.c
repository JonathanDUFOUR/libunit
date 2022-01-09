/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:43:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 13:01:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_unit.h"

/*
	Release every resources contained in the list the given unit `node` is in
*/
void	unit_clear(t_unit *const node)
{
	t_unit	*curr;
	t_unit	*next;
	t_unit	*prev;

	curr = node->next;
	while (curr)
	{
		next = curr->next;
		free((void *)curr);
		curr = next;
	}
	curr = node->prev;
	while (curr)
	{
		prev = curr->prev;
		free((void *)curr);
		curr = prev;
	}
	free((void *)node);
}
