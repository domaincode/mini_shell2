/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:57:58 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 13:27:58 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	ft_print_error_fd(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
}

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->str);
		free(env);
		env = tmp;
	}
}

void	ft_print_export(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		printf("%s %s\n", "declare -x ", env->str);
		env = env->next;
	}
	ft_free_env(tmp);
}

void	ft_print_env(t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (env->next != tmp)
	{
		i++;
		printf("%s\n", env->str);
		env = env->next;
	}
	printf("%s\n", env->str);
}
