/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_launch.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 06:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 19:01:19 by jodufour         ###   ########.fr       */
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

int	cvrt_c_launcher(void);
int	cvrt_s_launcher(void);
int	cvrt_p_launcher(void);
int	cvrt_d_launcher(void);
int	cvrt_i_launcher(void);
int	cvrt_u_launcher(void);
int	cvrt_x_launcher(void);
int	literal_launcher(void);

static t_launch const	g_launch[] = {
{"cvrt c", cvrt_c_launcher},
{"cvrt s", cvrt_s_launcher},
{"cvrt p", cvrt_p_launcher},
{"cvrt d", cvrt_d_launcher},
{"cvrt i", cvrt_i_launcher},
{"cvrt u", cvrt_u_launcher},
{"cvrt x", cvrt_x_launcher},
{"literal", literal_launcher},
{0}
};

#endif
