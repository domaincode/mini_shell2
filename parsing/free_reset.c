/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:26:22 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 18:58:51 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec/exec.h"
#include "parsing.h"

void	exec_free_reset(t_data *data)
{
	ft_execution(data);
	ft_free_stack(data->cmd);
	free_cmd(&data->cmd);
	free_token(&data->token);
	if (data->envp)
		free(data->envp);
	g_signal.g_signal_pid = 0;
	g_signal.signal_flag = false;
}
