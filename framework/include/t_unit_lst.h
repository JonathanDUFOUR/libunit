/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_unit_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:09:02 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 06:34:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_UNIT_LST_H
# define T_UNIT_LST_H

# include <stddef.h>
# include "t_unit.h"

typedef struct s_unit_lst	t_unit_lst;

struct s_unit_lst
{
	t_unit	*head;
	t_unit	*tail;
	size_t	size;
};

int		unit_lst_add_back(t_unit_lst *const lst,
			char const *funcname, char const *testname, t_fct const call)
		__attribute__((nonnull));
int		unit_lst_run(t_unit_lst *const lst)
		__attribute__((nonnull));

void	unit_lst_clear(t_unit_lst *const lst)
		__attribute__((nonnull));
void	unit_lst_push_back(t_unit_lst *const lst, t_unit *const node)
		__attribute__((nonnull));

#endif
