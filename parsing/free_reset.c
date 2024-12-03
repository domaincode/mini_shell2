/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:26:22 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 01:34:59 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"
# include "../exec/exec.h"

void	free_reset(t_data *data)
{
	ft_free_stack(data->cmd);
	free_cmd(&data->cmd);    			
	free_token(&data->token);
	g_signal_pid = 0;
}
