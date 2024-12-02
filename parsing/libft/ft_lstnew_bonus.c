/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:30:43 by kbelmajd          #+#    #+#             */
/*   Updated: 2023/12/07 13:23:14 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (0);
	n->content = content;
	n->next = NULL;
	return (n);
}
