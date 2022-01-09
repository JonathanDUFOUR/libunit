/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_unit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:11:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 18:22:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_UNIT_H
# define T_UNIT_H

# include <stdbool.h>
# include "t_fct.h"

typedef struct s_unit	t_unit;

struct s_unit
{
	char const	*funcname;
	char const	*testname;
	t_fct		call;
	t_unit		*next;
	t_unit		*prev;
};

int		unit_run(t_unit *const node)
		__attribute__((nonnull));

void	unit_clear(t_unit *const node)
		__attribute__((nonnull));

t_unit	*unit_new(char const *funcname, char const *testname, t_fct const call)
		__attribute__((nonnull));

#endif
