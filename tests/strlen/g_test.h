/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:58:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 09:17:37 by jodufour         ###   ########.fr       */
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

int	strlen_basic_test(void);
int	strlen_null_test(void);
int	strlen_bad_len_test(void);
int	strlen_uninitialized_test(void);
int	strlen_lorem_ipsum_test(void);
int	strlen_abort_test(void);

static t_test const		g_test[] = {
{"Basic test", strlen_basic_test},
{"NULL test", strlen_null_test},
{"Bad len test", strlen_bad_len_test},
{"Uninitialized test", strlen_uninitialized_test},
{"Lorem ipsum test", strlen_lorem_ipsum_test},
{"Abort test", strlen_abort_test},
{0}
};

#endif
