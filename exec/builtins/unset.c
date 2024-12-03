/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:59:19 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 13:26:08 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static int	ft_check_duplicate1(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != '=' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == '=' && s2[i] == 0)
		return (0);
	else
		return (1);
}

static t_env	*ft_get_duplicate1(t_env *env, char *to_find)
{
	t_env	*tmp;

	if (to_find && to_find[0] == '_' && (to_find[1] == '=' || to_find[1] == '\0'))
		return (NULL);
	tmp = env;
	while (env->next != tmp)
	{
		if (ft_check_duplicate1(env->str, to_find) == 0)
		{
			return (env);
		}
		env = env->next;
	}
	if (ft_check_duplicate1(env->str, to_find) == 0)
		return (env);
	return (NULL);
}

int	ft_unset(t_env **env, char **cmd_param)
{
	t_env	*node;
	int		i;

	i = 1;
	while (cmd_param[i])
	{
		node = ft_get_duplicate1(*env, cmd_param[i]);
		if (node)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			if (!ft_strncmp((*env)->str, node->str, ft_strlen(node->str)))
				*env = node->next;
			free(node->str);
			free(node);
		}
		i++;
	}
	return (0);
}
