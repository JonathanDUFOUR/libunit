/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_launch.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 06:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:08:14 by jodufour         ###   ########.fr       */
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

int	math_launcher(void);
int	strchr_launcher(void);
int	strcmp_launcher(void);
int	strcpy_launcher(void);
int	strlen_launcher(void);

static t_launch const	g_launch[] = {
{"math", math_launcher},
{"strchr", strchr_launcher},
{"strcmp", strcmp_launcher},
{"strcpy", strcpy_launcher},
{"strlen", strlen_launcher},
{0}
};

#endif
