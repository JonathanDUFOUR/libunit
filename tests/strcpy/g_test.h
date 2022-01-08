/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:00:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:55:56 by jodufour         ###   ########.fr       */
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

int	strcpy_basic_test(void);
int	strcpy_const_test(void);
int	strcpy_freed_test(void);
int	strcpy_misaligned_test(void);

static t_test const		g_test[] = {
{"Basic test", strcpy_basic_test},
{"Const test", strcpy_const_test},
{"Freed test", strcpy_freed_test},
{"Misaligned test", strcpy_misaligned_test},
{0}
};

#endif
