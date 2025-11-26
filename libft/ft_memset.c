/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:49:28 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:28:29 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		dest[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	str[24];

// 	str[] = "Hallo guys, how are you?";
// 	puts(str);
// 	ft_memset(str, '#', 7);
// 	puts(str);
// 	return (0);
// }
