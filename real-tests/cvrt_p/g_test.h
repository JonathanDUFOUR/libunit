/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 20:40:02 by jodufour         ###   ########.fr       */
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

int	cvrt_p_null_test(void);
int	cvrt_p_42_test(void);
int	cvrt_p_memcmp_test(void);
int	cvrt_p_printf_test(void);
int	cvrt_p_longmax_test(void);
int	cvrt_p_uintptrmax_test(void);

static t_test const		g_test[] = {
{"NULL", cvrt_p_null_test},
{"42", cvrt_p_42_test},
{"&memcmp", cvrt_p_memcmp_test},
{"&printf", cvrt_p_printf_test},
{"LONGMAX", cvrt_p_longmax_test},
{"UINTPTRMAX", cvrt_p_uintptrmax_test},
{0}
};

#endif
