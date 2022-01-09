/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:15:17 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 22:22:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "unit.h"
#include "lookup_launch.h"

static int	__internal_err(int const i)
{
	char const	*ptr = g_launch[i].name;

	while (*ptr)
		++ptr;
	write(STDERR_FILENO, "Internal error encountered while running: ", 42);
	write(STDERR_FILENO, g_launch[i].name, (size_t)(ptr - g_launch[i].name));
	write(STDERR_FILENO, "tests\n", 6);
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
	int	ret;
	int	i;

	i = 0;
	while (g_launch[i].name && g_launch[i].call)
	{
		ret = g_launch[i].call();
		if (ret == EXIT_FAILURE)
			return (__internal_err(i));
		++i;
	}
	return (EXIT_SUCCESS);
}

static int	__specific_launchers(char const **av)
{
	int	ret;
	int	i;

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
			++i;
		}
		++av;
	}
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
	{
		if (!__strcmp(av[1], "-o"))
		{
			if (av[2] && output_to_logfile(av[2]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			if (ac == 3)
				return (__every_launchers());
			else if (ac > 3)
				return (__specific_launchers(av + 3));
		}
		return (__specific_launchers(av + 1));
	}
}
