/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_result.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:59:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 15:25:07 by jodufour         ###   ########.fr       */
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
{0, GREEN "OK" RESET},
{-1, RED "KO" RESET},
{-2, RED "TIMEOUT" RESET},
{SIGSEGV, RED "SIGSEGV" RESET},
{SIGBUS, RED "SIGBUS" RESET},
{SIGABRT, RED "SIGABRT" RESET},
{SIGFPE, RED "SIGFPE" RESET},
{SIGILL, RED "SIGILL" RESET},
{SIGPIPE, RED "SIGPIPE" RESET},
{0}
};

#endif
