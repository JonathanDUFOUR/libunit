/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:22:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 07:42:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_unit.h"

/*
	Allocate a new unit node and set its attribute accordingly
*/
t_unit	*unit_new(char const *funcname, char const *testname, t_fct const call)
{
	t_unit	*node;

	node = malloc(sizeof(t_unit));
	if (!node)
		return (NULL);
	node->funcname = funcname;
	node->testname = testname;
	node->call = call;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
