/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lst_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 06:17:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 15:17:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "t_unit_lst.h"
#include "internal_functions.h"
/*
	Run each function contained in the given unit list `lst` in a child process
*/
int	unit_lst_run(t_unit_lst *const lst)
{
	t_unit	*curr;
	size_t	check;
	int		ret;

	if (write(STDOUT_FILENO, "", 0) == -1)
		return (EXIT_FAILURE);
	check = 0;
	curr = lst->head;
	while (curr)
	{
		ret = unit_run(curr);
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
		check += (size_t) !ret;
		curr = curr->next;
	}
	putsize(check);
	write(STDOUT_FILENO, "/", 1);
	putsize(lst->size);
	write(STDOUT_FILENO, " tests checked\n", 15);
	return (EXIT_SUCCESS);
}
