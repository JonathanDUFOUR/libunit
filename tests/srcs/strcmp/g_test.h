/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 14:38:49 by                  ###   ########.fr       */
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

int	strcmp_basic_test(void);
int	strcmp_null_test(void);
int	strcmp_illegal_test(void);

static t_test const		g_test[] = {
{"Basic test", strcmp_basic_test},
{"NULL test", strcmp_null_test},
{"Illegal test", strcmp_illegal_test},
{0}
};

#endif
