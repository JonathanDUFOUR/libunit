/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lst_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:45:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 08:08:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_unit_lst.h"

/*
	Allocate a new unit node, set its attributes to the given ones
	and append it at the end of the given unit list `lst` 
*/
int	unit_lst_add_back(t_unit_lst *const lst,
	char const *funcname, char const *testname, t_fct const call)
{
	t_unit *const	node = unit_new(funcname, testname, call);

	if (!node)
		return (EXIT_FAILURE);
	unit_lst_push_back(lst, node);
	return (EXIT_SUCCESS);
}
