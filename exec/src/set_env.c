/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:25 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 14:02:47 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

t_env	*ft_last_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (env->next != tmp)
	{
		env = env->next;
	}
	return (env);
}

t_env	*ft_new_env(char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}

void	ft_env_add_back(t_env **list, t_env *node)
{
	t_env	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = node;
			return ;
		}
		tmp = tmp->next;
	}
}

t_env	*ft_env_setup(t_env *env)
{
	t_env	*stack;
	t_env	*node;
	t_env	*tmp;

	tmp = env;
	stack = NULL;
	while (env->next != tmp)
	{
		node = ft_new_env(env->str);
		ft_env_add_back(&stack, node);
		env = env->next;
	}
	node = ft_new_env(env->str);
	ft_env_add_back(&stack, node);
	return (stack);
}
