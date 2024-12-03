/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:11:32 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 16:53:48 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	ft_numeric_parcing(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

static int	ft_no_exit(t_cmd *stack)
{
	if (!stack->cmd_param[1])
		return (0);
	else if (!ft_numeric_parcing(stack->cmd_param[1]) && !stack->cmd_param[2])
		return (ft_atoi(stack->cmd_param[1]));
	else if (!ft_numeric_parcing(stack->cmd_param[1]) && stack->cmd_param[2])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		return (1);
	}
	else
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(stack->cmd_param[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (2);
	}
	return (0);
}

int	ft_exit(t_cmd *stack)
{
	if (stack->prev || stack->next)
		return (ft_no_exit(stack));
	else if (!stack->cmd_param[1])
	{
		printf("exit\n");
		return (0);
	}
	else if (!ft_numeric_parcing(stack->cmd_param[1]) && !stack->cmd_param[2])
	{
		printf("exit\n");
		return (ft_atoi(stack->cmd_param[1]));
	}
	else if (!ft_numeric_parcing(stack->cmd_param[1]) && stack->cmd_param[2])
	{
		ft_print_error_fd("exit\n", "minishell: exit: ",
			"too many arguments\n");
		return (1);
	}
	else
	{
		ft_print_error_fd("minishell: exit: ", stack->cmd_param[1],
			": numeric argument required\n");
		return (2);
	}
}
