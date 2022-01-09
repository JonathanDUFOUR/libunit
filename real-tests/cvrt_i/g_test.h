/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 19:59:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_TEST_H
# define G_TEST_H

# include "t_fct.h"

typedef struct s_test	t_test;

struct s_test
{
	char const	*name;
	t_fct const	call;
};

int	cvrt_i_0_test(void);
int	cvrt_i_42_test(void);
int	cvrt_i_m42_test(void);
int	cvrt_i_intmax_test(void);
int	cvrt_i_intmin_test(void);
int	cvrt_i_uintmax_test(void);

static t_test const		g_test[] = {
{"0", cvrt_i_0_test},
{"42", cvrt_i_42_test},
{"-42", cvrt_i_m42_test},
{"INTMAX", cvrt_i_intmax_test},
{"INTMIN", cvrt_i_intmin_test},
{"UINTMAX", cvrt_i_uintmax_test},
{0}
};

#endif
