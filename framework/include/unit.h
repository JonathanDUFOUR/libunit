/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 05:17:30 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 18:58:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# include <stddef.h>

int		redirect_init(void);
int		redirect_end(void);
int		redirect_std_out_to_log(char const **av);

#endif
