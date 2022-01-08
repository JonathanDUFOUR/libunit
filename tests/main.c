/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:15:17 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 09:23:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "unit.h"
#include "lookup_launch.h"

void	ratio(size_t const checked, size_t const total);

static int	__internal_err(int const i)
{
	char const	*ptr = g_launch[i].name;

	while (*ptr)
		++ptr;
	write(STDERR_FILENO, "Internal error encountered while running: ", 42);
	write(STDERR_FILENO, g_launch[i].name, (size_t)(ptr - g_launch[i].name));
	return (EXIT_FAILURE);
}

static int	__strcmp(char const *str0, char const *str1)
{
	while (*str0 && *str0 == *str1)
	{
		++str0;
		++str1;
	}
	return (*str0 - *str1);
}

static int	__every_launchers(void)
{
	size_t	checked;
	size_t	i;
	int		ret;

	checked = 0;
	i = 0;
	while (g_launch[i].name && g_launch[i].call)
	{
		ret = g_launch[i].call();
		if (ret == EXIT_FAILURE)
			return (__internal_err(i));
		checked += (size_t) !ret;
		++i;
	}
	ratio(checked, i);
	return (EXIT_SUCCESS);
}

static int	__specific_launchers(char const **av)
{
	size_t	checked;
	size_t	total;
	size_t	i;
	int		ret;

	checked = 0;
	total = 0;
	while (*av)
	{
		i = 0;
		while (g_launch[i].name && g_launch[i].call)
		{
			if (__strcmp(g_launch[i].name, *av) && ++i)
				continue ;
			ret = g_launch[i].call();
			if (ret == EXIT_FAILURE)
				return (__internal_err(i));
			checked += (size_t) !ret;
			++total;
			++i;
		}
		++av;
	}
	ratio(checked, total);
	return (EXIT_SUCCESS);
}

int	main(int const ac, char const **av)
{
	if (write(STDOUT_FILENO, "", 0) == -1)
	{
		write(STDERR_FILENO, "Error: cannot write on stdout\n", 30);
		return (EXIT_FAILURE);
	}
	if (ac == 1)
		return (__every_launchers());
	else
		return (__specific_launchers(av + 1));
}
