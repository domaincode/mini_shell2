/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:20:11 by mel-mans          #+#    #+#             */
/*   Updated: 2024/12/03 00:27:36 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	fill_cmd(t_data *data, t_token *tmp)
{
	data->cmd->prev->cmd_param = get_param(data, tmp);
	if (!get_infile(data, tmp, data->cmd->prev) && \
	data->cmd->prev->infile != -1)
		return (false);
	if (data->cmd->prev->infile == -1)
	{
		data->cmd->prev->skip_cmd = true;
		data->cmd->prev->outfile = -1;
		return (true);
	}
	if (!get_outfile(tmp, data->cmd->prev, data) && \
	data->cmd->prev->outfile != -1)
		return (false);
	if (data->cmd->prev->outfile == -1)
	{
		if (data->cmd->prev->infile >= 0)
			close(data->cmd->prev->infile);
		data->cmd->prev->skip_cmd = true;
		data->cmd->prev->infile = -1;
		return (true);
	}
	if (!data->cmd->prev->cmd_param)
		free_all(data, "malloc error\n", 1);
	return (true);
}

static bool	norm(t_data *data, t_token *tmp)
{
	if (!append_cmd(&data->cmd, -2, -2, NULL))
		free_all(data, "malloc error\n", 1);
	if (!fill_cmd(data, tmp))
	{
		data->exit_code = 2;
		return (false);
	}
	return (true);
}

bool	create_list_cmd(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!norm(data, tmp))
		return (false);
	tmp = tmp->next;
	while (tmp != data->token)
	{
		if (tmp->prev->type == PIPE)
		{
			if (!norm(data, tmp))
				return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}
