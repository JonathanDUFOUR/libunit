/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:17:30 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 22:18:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# ifndef TIMOUT_VALUE
#  define TIMEOUT_VALUE 10
# endif

# include <stddef.h>

int		output_to_logfile(char const *logfile_name)
		__attribute__((nonnull));
int		redirect_init(void);
int		redirect_end(void);

#endif
