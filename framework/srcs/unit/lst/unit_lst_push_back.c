/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lst_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:42:59 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 07:43:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_unit_lst.h"

/*
	Append the given unit `node` at the end of the given unit list `lst`
	Update the list's data accordingly
*/
void	unit_lst_push_back(t_unit_lst *const lst, t_unit *const node)
{
	if (!lst->size)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		node->prev = lst->tail;
		lst->tail->next = node;
		lst->tail = node;
	}
	++lst->size;
}
