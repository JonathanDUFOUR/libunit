/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_free_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:46:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 15:47:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strlen_free_test(void)
{
	void	*const ptr = &strlen;

	free(ptr);
	return (0);
}
