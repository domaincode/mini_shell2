/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:42:37 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/06/10 17:43:03 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*dest;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = malloc(s1len + s2len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, s1len + 1);
	ft_strlcat(dest, s2, s1len + s2len + 1);
	if (s1)
		free(s1);
	return (dest);
}

static char	*ft_getline(int fd, char *line)
{
	char	*buffer;
	ssize_t	cnt;

	buffer = malloc(((long)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		cnt = read(fd, buffer, BUFFER_SIZE);
		if (cnt <= 0)
		{
			if (cnt == 0)
				break ;
			if (line)
				free(line);
			free(buffer);
			return (NULL);
		}
		buffer[cnt] = '\0';
		line = ft_strjoin1(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*ft_get_rest(char *rest, char *dest)
{
	char	*line_rest;

	line_rest = malloc(ft_strlen(dest));
	if (!line_rest)
		return (NULL);
	ft_strlcpy(line_rest, dest + 1, ft_strlen(dest));
	free(rest);
	return (line_rest);
}

static char	*ft_new_line(char *rest, char *dest)
{
	char	*line;
	size_t	i;

	i = ft_strlen(rest) - ft_strlen(dest);
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, rest, i + 2);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*dest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_getline(fd, rest);
	if (!rest)
		return (NULL);
	dest = ft_strchr(rest, '\n');
	if (dest && *(dest + 1) != '\0')
	{
		line = ft_new_line(rest, dest);
		rest = ft_get_rest(rest, dest);
	}
	else
	{
		line = rest;
		rest = NULL;
	}
	return (line);
}
