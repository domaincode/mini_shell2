/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:20:41 by mel-mans          #+#    #+#             */
/*   Updated: 2024/11/28 11:20:41 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}

// #include <stdio.h>
// 
// void main()
// {
	// printf("%ld\n", ft_strlen("un truc un peu long puet etre"));
// }