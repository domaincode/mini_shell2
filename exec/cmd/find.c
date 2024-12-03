/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:46:18 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 13:58:45 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static char	*find_builtins(char *str)
{
	int	acc_return;

	if (check_builtins(str) == true)
	{
		return (ft_strdup(str));
	}
	else if (ft_strchr(str, '/'))
	{
		acc_return = access(str, X_OK);
		if (!acc_return)
			return (ft_strdup(str));
		else
		{
			ft_putstr_fd("minishell : ", 2);
			perror(str);
		}
	}
	return (NULL);
}

static char	*find_programme(char *str, t_env *env)
{
	char	**arr;
	char	*path;
	char	*new_path;
	int		i;
	int		acc_return;

	i = 0;
	arr = my_split(ft_get_path(env), ':');
	if (!arr || !*arr)
		return (NULL);
	while (arr[i])
	{
		path = ft_strjoin(arr[i++], "/");
		new_path = ft_strjoin(path, str);
		free(path);
		acc_return = access(new_path, X_OK);
		if (!acc_return)
			break ;
		ft_free_set_null(&new_path);
	}
	free_split(arr);
	return (new_path);
}

static char	*ft_its_abin(t_cmd *stack, t_data *data)
{
	stack->path = find_programme(stack->cmd_param[0], data->env);
	if (stack->path == NULL)
	{
		stack->skip_cmd = true;
		ft_putstr_fd(stack->cmd_param[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		data->exit_code = 127;
		return (NULL);
	}
	return (stack->path);
}

int	ft_check_cmd(t_cmd *stack, t_data *data)
{
	if (stack->skip_cmd || (stack->next && stack->next->skip_cmd))
	{
		data->exit_code = 1;
		return (1);
	}
	if (!stack->cmd_param || !stack->cmd_param[0])
		return (1);
	stack->path = find_builtins(stack->cmd_param[0]);
	if (stack->path == NULL && ft_strchr(stack->cmd_param[0], '/'))
	{
		stack->skip_cmd = true;
		if (errno == EACCES)
			data->exit_code = 126;
		else
			data->exit_code = 127;
		return (1);
	}
	else if (stack->path == NULL && !ft_strchr(stack->cmd_param[0], '/'))
	{
		stack->path = ft_its_abin(stack, data);
		if (stack->path == NULL)
			return (1);
	}
	return (0);
}
