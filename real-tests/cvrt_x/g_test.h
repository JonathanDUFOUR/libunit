/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 21:05:33 by jodufour         ###   ########.fr       */
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

int	cvrt_x_0_test(void);
int	cvrt_x_42_test(void);
int	cvrt_x_123456_test(void);
int	cvrt_x_intmax_test(void);
int	cvrt_x_uintmax_test(void);
int	cvrt_x_longmax_test(void);

static t_test const		g_test[] = {
{"0", cvrt_x_0_test},
{"42", cvrt_x_42_test},
{"123456", cvrt_x_123456_test},
{"INTMAX", cvrt_x_intmax_test},
{"UINTMAX", cvrt_x_uintmax_test},
{"LONGMAX", cvrt_x_longmax_test},
{0}
};

#endif
