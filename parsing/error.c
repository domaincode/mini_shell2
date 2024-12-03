/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:20:21 by mel-mans          #+#    #+#             */
/*   Updated: 2024/12/03 00:20:22 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	check_error(t_token *tmp, t_data *data)
{
	if (tmp->type == TRUNC)
	{
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
	}
	else if (tmp->type == APPEND)
	{
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
	}
	else if (tmp->type == INPUT)
	{
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
	}
	else if (tmp->type == HEREDOC)
	{
		if (tmp == tmp->next || tmp->next->type <= 5)
			return (print_error_token(tmp, data));
	}
	return (true);
}

bool	get_out(t_token *token, t_data *data)
{
	t_token	*tmp;

	tmp = token;
	while (token->next != tmp)
	{
		if (!check_error(token, data))
			return (false);
		token = token->next;
	}
	if (!check_error(token, data))
		return (false);
	return (true);
}
