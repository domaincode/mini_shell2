/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:33:19 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 13:47:45 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

bool	check_builtins(char *str)
{
	if (str == NULL)
		return (false);
	if (!ft_strncmp(str, "echo", ft_strlen(str)))
		return (true);
	if (!ft_strncmp(str, "cd", ft_strlen(str)))
		return (true);
	if (!ft_strncmp(str, "pwd", ft_strlen(str)))
		return (true);
	if (!ft_strncmp(str, "export", ft_strlen(str)))
		return (true);
	if (!ft_strncmp(str, "unset", ft_strlen(str)))
		return (true);
	if (!ft_strncmp(str, "env", ft_strlen(str)))
		return (true);
	if (!ft_strncmp(str, "exit", ft_strlen(str)))
		return (true);
	return (false);
}

int	ft_exec_builtins(t_cmd *stack, t_data *data)
{
	char	*cmd;

	cmd = stack->cmd_param[0];
	if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		data->exit_code = ft_echo(stack->cmd_param);
	if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		data->exit_code = ft_cd(stack->cmd_param);
	if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		data->exit_code = ft_pwd();
	if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
		data->exit_code = ft_env(data->env);
	if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		data->exit_code = ft_export(data->env, stack->cmd_param);
	if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
		data->exit_code = ft_unset(&data->env, stack->cmd_param);
	if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
	{
		data->exit_code = ft_exit(stack);
		exit(data->exit_code);
	}
	return (data->exit_code);
}

int	ft_wait(t_data *data)
{
	int	g_status;

	while (waitpid(-1, &g_status, 0) > 0)
	{
		if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
		else if (WIFSIGNALED(g_status))
			g_status = 128 + WTERMSIG(g_status);
		data->exit_code = g_status;
	}
	return (0);
}
