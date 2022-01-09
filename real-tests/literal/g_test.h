/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:39:13 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 21:19:50 by jodufour         ###   ########.fr       */
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

int	literal_null_test(void);
int	literal_empty_test(void);
int	literal_short_test(void);
int	literal_medium_test(void);
int	literal_large_test(void);

static t_test const		g_test[] = {
{"NULL", literal_null_test},
{"Empty", literal_empty_test},
{"Short", literal_short_test},
{"Medium", literal_medium_test},
{"Large", literal_large_test},
{0}
};

#endif
