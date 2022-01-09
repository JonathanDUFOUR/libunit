/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 19:04:18 by jodufour         ###   ########.fr       */
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

int	cvrt_c_a_test(void);
int	cvrt_c_S_test(void);
int	cvrt_c_m_test(void);
int	cvrt_c_R_test(void);
int	cvrt_c_zero_test(void);

static t_test const		g_test[] = {
{"'a'", cvrt_c_a_test},
{"'S'", cvrt_c_S_test},
{0}
};

#endif
