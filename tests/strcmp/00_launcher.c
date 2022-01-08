/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:21:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 07:01:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "g_test.h"
#include "t_unit_lst.h"

int	strcmp_launcher(void)
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
		&& !unit_lst_add_back(&lst, "STRCMP", g_test[i].name, g_test[i].call))
		++i;
	if (!g_test[i].name && !g_test[i].call)
		ret = unit_lst_run(&lst);
	unit_lst_clear(&lst);
	return (ret);
}
