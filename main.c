/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:36:50 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 18:59:27 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec/exec.h"
#include "parsing/parsing.h"

t_signal	g_signal;

int	make_env(t_data *data, char **env)
{
	t_env	*list;
	int		i;
	char	*tmp;

	if (!(*env))
		return (make_env2(data));
	i = -1;
	list = NULL;
	while (env[++i])
	{
		tmp = ft_strdup(env[i]);
		if (!tmp)
			return (free_list(&list));
		if (!append(&list, tmp))
			return (free_list(&list));
	}
	data->env = list;
	return (1);
}

void	init_data(t_data *data)
{
	data->env = NULL;
	data->envp = NULL;
	data->token = NULL;
	data->cmd = NULL;
	data->exit_code = 0;
	signals();
	g_signal.g_signal_pid = 0;
	g_signal.signal_flag = 0;
}

bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
	{
		free(line);
		return (true);
	}
	return (false);
}

bool	parseline(t_data *data, char *line)
{
	if (open_quote(data, line))
	{
		free(line);
		return (false);
	}
	if (!replace_dollar(&line, data) || !create_list_token(&data->token, line))
		free_all(data, "malloc error\n", 1);
	free(line);
	if (data->token && data->token->prev->type == PIPE)
	{
		write(2, "Error: Unclosed pipe\n", 21);
		data->exit_code = 2;
		free_token(&data->token);
		return (false);
	}
	if (!data->token || !create_list_cmd(data))
	{
		free_token(&data->token);
		free_cmd_circle(&data->cmd);
		return (false);
	}
	return (check_pipe(data));
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*line;

	if (argc == 1 && argv[0])
	{
		init_data(&data);
		if (!make_env(&data, env))
			return (0);
		while (1)
		{
			data.cmd = NULL;
			line = readline("minishell> ");
			if (g_signal.signal_flag)
				data.exit_code = 130;
			if (!line)
				free_all(&data, "exit\n", data.exit_code);
			if (empty_line(line))
				continue ;
			add_history(line);
			if (!parseline(&data, line))
				continue ;
			exec_free_reset(&data);
		}
	}
	return (0);
}
