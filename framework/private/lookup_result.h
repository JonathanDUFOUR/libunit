/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_result.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:59:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_RESULT_H
# define LOOKUP_RESULT_H

# include <signal.h>
# include "colors.h"

typedef struct s_result	t_result;

struct s_result
{
	int const	status;
	char const	*msg;
};

static t_result const	g_result[] = {
{0, GREEN_FG "OK" RESET},
{-1, RED_FG "KO" RESET},
{-2, RED_FG "TIMEOUT" RESET},
{SIGSEGV, RED_FG "SIGSEGV" RESET},
{SIGBUS, RED_FG "SIGBUS" RESET},
{SIGABRT, RED_FG "SIGABRT" RESET},
{SIGFPE, RED_FG "SIGFPE" RESET},
{SIGILL, RED_FG "SIGILL" RESET},
{SIGPIPE, RED_FG "SIGPIPE" RESET},
{0}
};

#endif
