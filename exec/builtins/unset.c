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

static int	unset_check_duplicate(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != '=' && s1[i] == s2[i])
	{
		i++;
	}
	if ((s1[i] ==  s2[i]) || (s1[i] == '=' && !s2[i]) )
		return (0);
	else
		return (1);
}

 static t_env	*unset_get_duplicate(t_env *env, char *to_find)
{
	t_env	*tmp;

	if (to_find && to_find[0] == '_' && (to_find[1] == '=' || to_find[1] == '\0'))
		return (NULL);
	tmp = env;
	while (env->next != tmp)
	{
		if (unset_check_duplicate(env->str, to_find) == 0)
		{
			return (env);
		}
		env = env->next;
	}
	if (unset_check_duplicate(env->str, to_find) == 0)
		return (env);
	return (NULL);
}

int	ft_unset(t_env **env, char **cmd_param)
{
	t_env	*node;
	char	*dest;
	int		i;

	i = 1;
	while (cmd_param[i])
	{
		dest = ft_strchr(cmd_param[i], '=');
		if(dest)
		{
			i++;
			continue;
		}
		node = unset_get_duplicate(*env, cmd_param[i]);
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
