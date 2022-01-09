/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:37:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 10:40:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "internal.h"
#include "type/t_ctx.h"

char	*manage_text(char const *format, t_ctx *const ctx)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		ctx->fwidth = next - format;
	else
		ctx->fwidth = ft_strlen(format);
	write(1, format, ctx->fwidth);
	ctx->len += ctx->fwidth;
	format += ctx->fwidth;
	return ((char *)format);
}
