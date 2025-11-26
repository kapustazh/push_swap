/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:35:14 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:35:15 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		dest[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	str[] = "Hallo guys, how are you?";
// 	ft_bzero(str, 24);
// 	printf("%s\n", str);
// 	return (0); 
// }
