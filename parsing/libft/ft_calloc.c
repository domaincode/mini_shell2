/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:15:49 by mel-mans          #+#    #+#             */
/*   Updated: 2024/11/28 11:15:49 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	if (count != 0 && size != 0 && size > 2147483647 / count)
		return (NULL);
	i = -1;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (++i < count * size)
		tmp[i] = 0;
	return (tmp);
}
