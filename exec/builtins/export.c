/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:59 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 21:11:57 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	ft_sort(t_env *env)
{
	char	*tmp;
	t_env	*envlist;
	t_env	*env_tmp;

	envlist = env;
	env_tmp = env;
	while (env)
	{
		env_tmp = envlist;
		while (env_tmp && env_tmp->next)
		{
			if (ft_env_cmp(env_tmp->str, env_tmp->next->str) > 0)
			{
				tmp = env_tmp->str;
				env_tmp->str = env_tmp->next->str;
				env_tmp->next->str = tmp;
			}
			env_tmp = env_tmp->next;
		}
		env = env->next;
	}
}

void	ft_set_envirements1(t_env *env, char *cmd_param, t_env **node,
		t_env **new)
{
	char *dest;

	*node = ft_get_duplicate(env, cmd_param);
	dest = ft_strchr(cmd_param, '=');
	if (*node && dest)
	{
		free((*node)->str);
		(*node)->str = ft_strdup(cmd_param);
	}
	else if(*node && !dest)
		return ;
	else
	{
		*node = ft_last_env(env);
		*new = ft_new_env(cmd_param);
		(*node)->next = *new;
		(*new)->prev = env->prev;
		env->prev = *new;
		(*new)->next = env;
	}
}

int	ft_set_envirements(t_env *env, char **cmd_param)
{
	int		i;
	t_env	*new;
	t_env	*node;
	 //char	*dest;

	i = 1;
	while (cmd_param[i])
	{
			if (ft_export_parcing(cmd_param[i]) == 0 )
			{
				ft_set_envirements1(env, cmd_param[i], &node, &new);
			}
			else
			{
				ft_print_error_fd("minishell: export: `", cmd_param[i],
					"':  not a valid identifier\n");
				return (1);
			}
		i++;
	}
	return (0);
}

int	ft_export(t_env *env, char **cmd_param)
{
	t_env	*my_env;

	if (cmd_param[1])
	{
		return (ft_set_envirements(env, cmd_param));
	}
	else
	{
		my_env = ft_env_setup(env);
		ft_sort(my_env);
		ft_print_export(my_env);
	}
	return (0);
}
