/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:49:56 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:27:48 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *to, const void *from, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (!to && !from)
		return (NULL);
	dest = (unsigned char *)to;
	src = (const unsigned char *)from;
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (to);
}

// int	main(void)
// {
// 	char	str[50];
// 	char	str2[50];

// 	strcpy(str2, "Hallo guys, how are you?");
// 	ft_memcpy(str, str2, 5);
// 	puts(str);
// 	return (0);
// }
