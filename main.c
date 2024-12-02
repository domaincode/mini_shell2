#include "parsing/parsing.h"
#include "./exec/exec.h"

pid_t	g_signal_pid;

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
	//data->exit_code = 0;
	signals();
	g_signal_pid = 0;
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
	//t_cmd	*tmp;
	if (open_quote(data, line))
	{
		free(line);
		return (false);
	}
	if (!replace_dollar(&line, data) || !create_list_token(&data->token, line))
		free_all(data, "malloc error\n", 1);
	//if (*line)
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
		free_cmd(&data->cmd);
		return (false);
	}
	// tmp = data->cmd;
	// while (tmp->next != data->cmd)
	// {
	// 	printf("infile = %d, outfile = %d\n",  tmp->infile, tmp->outfile);
	// 	tmp = tmp->next;
	// }
	// printf("infile = %d, outfile = %d\n",  tmp->infile, tmp->outfile);
	return (check_pipe(data));
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*line;
	//printf("%d\n", getpid());

	if (argc == 1 && argv[0])
	{
		init_data(&data);
		data.exit_code = 0;
		if (!make_env(&data, env))
		{
			return(0);
			//free_all(&data, "", 1);
		}
		while (1)
		{
			//init_data(&data);
			data.cmd = NULL;
			line = readline("minishell> ");
			if (!line)
				free_all(&data, "exit\n", data.exit_code);
			if (empty_line(line))
				continue ;
			add_history(line);
			if (!parseline(&data, line))
				continue ;
			if(ft_execution(&data))
			{
				continue ;
			}
			 ft_free_stack(data.cmd);
			 free_cmd(&data.cmd);    			
			 free_token(&data.token);
			//free(line);
		// 		if (data->envp)
		// free(data->envp);
		}
		// rl_clear_history();
		// free_all(&data, NULL, -1);
	}
	return (0);
}
