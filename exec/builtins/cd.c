/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:36:23 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 16:47:16 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	ft_cd(t_data *data, char **cmd_param)
{
	(void) data;
	if (cmd_param[1] == NULL)
		return (1);
	if (chdir(cmd_param[1]) == -1)
	{
		perror("cd");
		return (1);
	}
	if (cmd_param[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
		getcwd(NULL, 0);
	return (0);
}
