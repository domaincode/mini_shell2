/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:33:19 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 20:47:10 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

bool	check_builtins(char *str)
{
	if (str == NULL)
		return (false);
	else if (!ft_strcmp(str, "echo"))
		return (true);
	else if (!ft_strcmp(str, "cd"))
		return (true);
	else if (!ft_strcmp(str, "pwd"))
		return (true);
	else if (!ft_strcmp(str, "export"))
		return (true);
	else if (!ft_strcmp(str, "unset"))
		return (true);
	else if (!ft_strcmp(str, "env"))
		return (true);
	else if (!ft_strcmp(str, "exit"))
		return (true);
	return (false);
}

int	ft_exec_builtins(t_cmd *stack, t_data *data)
{
	char	*cmd;

	cmd = stack->cmd_param[0];
	if (!ft_strcmp(cmd, "echo"))
		data->exit_code = ft_echo(stack->cmd_param);
	else if (!ft_strcmp(cmd, "cd"))
		data->exit_code = ft_cd(data, stack->cmd_param);
	else if (!ft_strcmp(cmd, "pwd"))
		data->exit_code = ft_pwd(data->env);
	else if (!ft_strcmp(cmd, "env"))
		data->exit_code = ft_env(data->env);
	else if (!ft_strcmp(cmd, "export"))
		data->exit_code = ft_export(data->env, stack->cmd_param);
	else if (!ft_strcmp(cmd, "unset"))
		data->exit_code = ft_unset(&data->env, stack->cmd_param);
	else if (!ft_strcmp(cmd, "exit"))
		data->exit_code = ft_exit(stack, data);
	return (data->exit_code);
}

int	ft_wait(t_data *data)
{
	int	g_status;
	t_cmd *stack;

	stack = data->cmd;
	while (stack)
	{
		waitpid(stack->id, &g_status, 0);
		if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
		else if (WIFSIGNALED(g_status))
			g_status = 128 + WTERMSIG(g_status);
		data->exit_code = g_status;
		stack= stack->next;
	}
	return (0);
}
