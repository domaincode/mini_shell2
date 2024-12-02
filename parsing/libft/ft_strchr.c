/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:20:04 by mel-mans          #+#    #+#             */
/*   Updated: 2024/11/28 11:20:04 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = -1;
	while (string[++i])
		if (string[i] == (unsigned char)searchedChar)
			return ((char *)&string[i]);
	if (string[i] == (unsigned char)searchedChar)
		return ((char *)&string[i]);
	return (NULL);
}

// void main()
// {
// 	printf("%s\n", strchr("je cherche une lettre", 'e'));
// 	printf("%s\n", ft_strchr("je cherche une lettre", 'e'));
// 	char *f = NULL;
// 	printf("%d\n", (f || NULL));
// }