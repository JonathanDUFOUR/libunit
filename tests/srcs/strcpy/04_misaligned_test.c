/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_misaligned_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:53:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 22:39:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#if defined(__GNUC__)
# if defined(__i386__)
#  define ENABLE_ALIGN_X86 1
#  define ENABLE_ALIGN_X86_64 0
# elif defined(__x86_64__)
#  define ENABLE_ALIGN_X86 0
#  define ENABLE_ALIGN_X86_64 1
# endif
#endif

int	strcpy_misaligned_test(void)
{
	char		dst[42];
	char const	src[21] = "Wazaaaa";
	int			*iptr;
	char		*cptr;

	if (ENABLE_ALIGN_X86)
		__asm__("pushf\norl $0x40000,(%esp)\npopf");
	else if (ENABLE_ALIGN_X86_64)
		__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	cptr = malloc(sizeof(int) + 1);
	iptr = (int *)++cptr;
	*iptr = 42;
	free(--cptr);
	if (strcpy(dst, src) == dst && !strcmp(dst, src))
		return (0);
	else
		return (-1);
}
