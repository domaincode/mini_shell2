/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:32:35 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 19:58:31 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static int	ft_exec(t_cmd *stack, t_data *data)
{
	int	exec_return;

	if (check_builtins(stack->cmd_param[0]) == true)
	{
		exec_return = ft_exec_builtins(stack, data);
		if (exec_return)
			exit(exec_return);
	}
	else if (execve(stack->path, stack->cmd_param, data->envp) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(stack->cmd_param[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exit(126);
	}
	exit(0);
}

static int	ft_exec_one_cmd(t_data *data, t_cmd *stack)
{
	int	infile_org;
	int	outfile_org;
	int	exec_return;

	if (stack->outfile > 0)
		outfile_org = dup(1);
	if (stack->infile > 0)
		infile_org = dup(0);
	set_input_output(stack);
	exec_return = ft_exec_builtins(stack, data);
	data->exit_code = exec_return ;
	if (stack->outfile > 0)
	{
		dup2(outfile_org, 1);
		close(outfile_org);
	}
	if (stack->infile > 0)
	{
		dup2(infile_org, 0);
		close(infile_org);
	}
	return (exec_return);
}

static int	ft_exec_all_cmd(t_data *data, t_cmd *stack)
{
	while (stack)
	{
		if (ft_check_cmd(stack, data))
		{
			pipe(stack->fpipe);
			stack = stack->next;
			continue ;
		}
		if (stack->next)
			pipe(stack->fpipe);
		stack->id = fork();
		g_signal.g_signal_pid = stack->id;
		if (stack->id == 0)
		{
			signals2();
			set_input_output(stack);
			ft_exec(stack, data);
		}
		if (stack->prev)
		{
			close(stack->prev->fpipe[1]);
			close(stack->prev->fpipe[0]);
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_execution(t_data *data)
{
	ft_null(data->cmd);
	if (data->cmd && !data->cmd->next && data->cmd->skip_cmd == true)
	{
		data->exit_code = 1;
		return (0);
	}
	data->envp = lst_to_arr(data->env);
	if (!data->cmd->next && data->cmd->cmd_param
		&& check_builtins(data->cmd->cmd_param[0]) == true)
	{
		data->cmd->path = ft_strdup(data->cmd->cmd_param[0]);
		return (ft_exec_one_cmd(data, data->cmd));
	}
	else
	{
		ft_exec_all_cmd(data, data->cmd);
		ft_wait(data);
	}
	return (0);
}
