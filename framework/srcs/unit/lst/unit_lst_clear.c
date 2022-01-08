/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:24:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 06:32:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_unit_lst.h"

/*
	Release every resources contained in the given units list
	and update the list's data
*/
void	unit_lst_clear(t_unit_lst *const lst)
{
	t_unit	*next;

	while (lst->head)
	{
		next = lst->head->next;
		free((void *)lst->head);
		lst->head = next;
	}
	lst->tail = NULL;
	lst->size = 0;
}
