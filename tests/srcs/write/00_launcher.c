/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:19:10 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:55:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "g_test.h"
#include "t_unit_lst.h"

int	write_launcher(void)
{
	t_unit_lst	lst;
	int			ret;
	int			i;

	lst.head = NULL;
	lst.tail = NULL;
	lst.size = 0;
	ret = EXIT_FAILURE;
	i = 0;
	while (g_test[i].name && g_test[i].call
		&& !unit_lst_add_back(&lst, "WRITE", g_test[i].name, g_test[i].call))
		++i;
	if (!g_test[i].name && !g_test[i].call)
		ret = unit_lst_run(&lst);
	unit_lst_clear(&lst);
	return (ret);
}
