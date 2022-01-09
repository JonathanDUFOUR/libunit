/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:20:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 15:17:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FUNCTIONS_H
# define INTERNAL_FUNCTIONS_H

void	putsize(size_t const nb);
void	output_name(char const *funcname, char const *testname);

int		output_status(int const status);

#endif //INTERNAL_FUNCTIONS_H