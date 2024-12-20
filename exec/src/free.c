/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:25 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 14:02:32 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	ft_free_stack(t_cmd *stack)
{
	t_cmd	*tmp;

	while (stack)
	{
		tmp = stack->next;
		if (stack->path && stack->skip_cmd == false && \
		stack->cmd_param && stack->cmd_param[0])
			free(stack->path);
		stack = tmp;
	}
	return (0);
}

int	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
