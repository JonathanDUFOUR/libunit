/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 21:03:37 by jodufour         ###   ########.fr       */
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

int	cvrt_u_0_test(void);
int	cvrt_u_9_test(void);
int	cvrt_u_42_test(void);
int	cvrt_u_intmax_test(void);
int	cvrt_u_uintmax_test(void);
int	cvrt_u_longmax_test(void);

static t_test const		g_test[] = {
{"0", cvrt_u_0_test},
{"9", cvrt_u_9_test},
{"42", cvrt_u_42_test},
{"INTMAX", cvrt_u_intmax_test},
{"UINTMAX", cvrt_u_uintmax_test},
{"LONGMAX", cvrt_u_longmax_test},
{0}
};

#endif
