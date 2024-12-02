/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:30:10 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/11/30 16:30:38 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../exec.h"

int	ft_null(t_cmd *stack)
{
	t_cmd	*tmp;

	tmp = stack;
	while (stack->next != tmp)
	{
		stack = stack->next;
	}
	tmp->prev = NULL;
	stack->next = NULL;
	return (0);
}

char	**lst_to_arr(t_env *env)
{
	t_env	*lst;
	char	**dest;
	int		i;

	dest = NULL;
	i = 0;
	lst = env;
	dest = malloc(sizeof(char *) * (len_list(lst) + 1));
	if (!dest)
		return (NULL);
	dest[i] = (lst->str);
	lst = lst->next;
	i++;
	while (lst != env)
	{
		dest[i] = (lst->str);
		lst = lst->next;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	ft_free_set_null(char **path)
{
	free(*path);
	*path = NULL;
}

char	*ft_get_path(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (env->next != tmp)
	{
		if (ft_strncmp(env->str, "PATH=", 5) == 0)
			return (env->str + 5);
		env = env->next;
	}
	if (ft_strncmp(env->str, "PATH=", 5) == 0)
		return (env->str + 5);
	return (NULL);
}