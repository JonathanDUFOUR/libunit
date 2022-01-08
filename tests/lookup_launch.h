/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_launch.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 06:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:00:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_LAUNCH_H
# define LOOKUP_LAUNCH_H

# include "t_fct.h"

typedef struct s_launch	t_launch;

struct s_launch
{
	char const	*name;
	t_fct const	call;
};

int	strchr_launcher(void);
int	strcmp_launcher(void);
int	strlen_launcher(void);
int	math_launcher(void);
int	write_launcher(void);

static t_launch const	g_launch[] = {
{"strchr", strchr_launcher},
{"math", math_launcher},
{"strcmp", strcmp_launcher},
{"strlen", strlen_launcher},
{"write", write_launcher},
{0}
};

#endif
