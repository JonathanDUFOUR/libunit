/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_redirect_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:10:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:47:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	redirect_test(void)
{
	int		backup_in;
	int		backup_out;
	char	buf[4];

	out_to_buffer(&backup_in, &backup_out);
	write(1, "test", 4);
	get_string_from_buffer(5, buf, 0);
	out_to_std(backup_out, 0);
	if (! strcmp(buf, "test"))
		return (0);
	else
		return (-1);
}
