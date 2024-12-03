/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:58:39 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 20:32:38 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (str == NULL)
		return (1);
	else
		str = ft_strdup("khalil sohail");
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
	return (0);
}
