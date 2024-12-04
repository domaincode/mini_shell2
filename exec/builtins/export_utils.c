/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:56:53 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 21:14:26 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	ft_export_parcing(char *s)
{
	int	i;

	i = 0;
	if (ft_isalpha(s[i]) == 0 && s[i] != '_')
		return (1);
	while (s[i] && s[i] != '=')
	{
		if(s[i] == '+' && s[i + 1] == '=')
			return 0;
		if ((ft_isalnum(s[i]) == 0 && s[i] != '_'))
			return (1);
		i++;
	}
	return (0);
}

static int	export_check_duplicate(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != '=' && s1[i] == s2[i])
		i++;
	if ((s1[i] ==  s2[i]) || (s1[i] == '=' && !s2[i]) || (!s1[i] && s2[i] == '=') )
		return (0);
	if((s1[i] == '=' || !s1[i]) && (s2[i] == '+'))
		return (0);
	else
		return (1);
}


t_env	*export_get_duplicate(t_env *env, char *to_find)
{
	t_env	*tmp;


	tmp = env;
	while (env->next != tmp)
	{
		if (export_check_duplicate(env->str, to_find) == 0)
			return (env);
		env = env->next;
	}
	if (export_check_duplicate(env->str, to_find) == 0)
		return (env);
	return (NULL);
}
