/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:25 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 14:03:05 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static size_t	ft_strnbr(char const *s, char c)
{
	size_t	nbr;

	nbr = 0;
	while (s != NULL && *s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			nbr++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (nbr);
}

static char	*ft_makestrings(char const *s, char c)
{
	size_t	l;
	char	*string;

	l = 0;
	while (s[l] != c && s[l] != '\0')
		l++;
	string = (char *)malloc((l + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, s, l + 1);
	return (string);
}

static char	**ft_strsplit(char const *s, char c, char **array)
{
	size_t	i;

	i = 0;
	while (s != NULL && *s)
	{
		if (*s != c)
		{
			array[i] = ft_makestrings(s, c);
			if (array[i] == NULL)
			{
				while (i > 0)
					free(array[--i]);
				free(array);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**my_split(char const *s, char c)
{
	char	**array;
	size_t	nbr;

	nbr = ft_strnbr(s, c);
	array = (char **)malloc((nbr + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	return (ft_strsplit(s, c, array));
}
