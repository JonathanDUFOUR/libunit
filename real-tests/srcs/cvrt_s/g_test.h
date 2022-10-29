/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 20:41:42 by jodufour         ###   ########.fr       */
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

int	cvrt_s_null_test(void);
int	cvrt_s_empty_test(void);
int	cvrt_s_short_test(void);
int	cvrt_s_medium_test(void);
int	cvrt_s_large_test(void);
int	cvrt_s_multistring_test(void);

static t_test const		g_test[] = {
{"NULL", cvrt_s_null_test},
{"Empty", cvrt_s_empty_test},
{"Short", cvrt_s_short_test},
{"Medium", cvrt_s_medium_test},
{"Large", cvrt_s_large_test},
{"Multistring", cvrt_s_multistring_test},
{0}
};

#endif
