/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:17:38 by mel-mans          #+#    #+#             */
/*   Updated: 2024/11/28 11:17:38 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	next = *lst;
	while (next)
	{
		tmp = next;
		next = next->next;
		(*del)(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
