/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_misaligned_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:53:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 16:56:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	strcpy_misaligned_test(void)
{
	int *iptr;
	char *cptr;

#if defined(__GNUC__)
# if defined(__i386__)
	/* Enable Alignment Checking on x86 */
	__asm__("pushf\norl $0x40000,(%esp)\npopf");
# elif defined(__x86_64__)
	 /* Enable Alignment Checking on x86_64 */
	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
# endif
#endif

	cptr = malloc(sizeof(int) + 1);	    
	iptr = (int *) ++cptr;
	*iptr = 42;
	free(cptr);
	return (0);
}
