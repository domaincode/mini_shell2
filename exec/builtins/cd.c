/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:36:23 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/11/30 16:36:29 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../exec.h"

int	ft_cd(char **cmd_param)
{
	if (cmd_param[1] == NULL)
		return (1);
	if (chdir(cmd_param[1]) == -1)
	{
		// printf("heererrerere\n");
		perror("cd");
		return (1);
	}
	if (cmd_param[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	return (0);
}
