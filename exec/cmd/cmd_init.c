/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:42:47 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/11/30 15:43:06 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../exec.h"

static int	ft_set_input_output(t_cmd *stack)
{
	if (stack->infile > 0)
	{
		if (dup2(stack->infile, 0) == -1)
			return (1);
		close(stack->infile);
	}
	else if (stack->prev && stack->prev->skip_cmd == false)
	{
		// printf("ppppppppppppppppppppppppppppppppp\n");
		close(stack->prev->fpipe[1]);
		if (dup2(stack->prev->fpipe[0], 0) == -1)
			return (1);
		close(stack->prev->fpipe[0]);
	}
	return (0);
}

int	set_input_output(t_cmd *stack)
{
	if (ft_set_input_output(stack))
		return (1);
	if (stack->outfile > 0)
	{
		if (dup2(stack->outfile, STDOUT_FILENO) == -1)
			return (1);
		close(stack->outfile);
	}
	else if (stack->next && stack->next->skip_cmd == false)
	{
		// printf("111111:%s\n", stack->path);
		close(stack->fpipe[0]);
		if (dup2(stack->fpipe[1], 1) == -1)
		{
			// printf("error in dup2\n");
			return (1);
		}
		close(stack->fpipe[1]);
	}
	return (0);
}