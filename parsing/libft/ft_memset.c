/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mans <mel-mans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:19:22 by mel-mans          #+#    #+#             */
/*   Updated: 2024/11/28 11:19:22 by mel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*str;

	str = pointer;
	while (count--)
	{
		*str = (unsigned char) value;
		str++;
	}
	return (pointer);
}

// #include <stdio.h>
// #include "libft.h"
// #include <string.h>

// int main() {

//     int array [] = { 54, 85, 20, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     int length;

//     /* Display the initial values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n" );

//     /* Reset the memory bloc */
//     ft_memset( array, 'q', size );

//     /* Display the new values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n" );

//     return 0;
// }