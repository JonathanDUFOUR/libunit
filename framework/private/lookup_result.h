/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_result.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:59:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 08:39:44 by jodufour         ###   ########.fr       */
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
{SIGSEGV | (1 << 7), RED "SIGSEGV" RESET},
{SIGBUS | (1 << 7), RED "SIGBUS" RESET},
{SIGABRT | (1 << 7), RED "SIGABRT" RESET},
{SIGFPE | (1 << 7), RED "SIGFPE" RESET},
{SIGILL | (1 << 7), RED "SIGILL" RESET},
{0}
};

#endif
