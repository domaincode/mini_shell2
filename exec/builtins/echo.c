/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:39:20 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/11/30 16:39:26 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../exec.h"

static int	ft_check_options(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' || !str[i])
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_echo(char **args)
{
	int	i;
	int	indice;

	i = 1;
	indice = 0;
	while (args[i] && ft_check_options(args[i]) == 0)
	{
		indice = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (indice == 0)
	{
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
