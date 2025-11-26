/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:49:37 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:28:25 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (num == 0 || to == from)
		return (to);
	dest = (unsigned char *)to;
	src = (const unsigned char *)from;
	if (dest < src)
	{
		i = 0;
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = num;
		while (i--)
			dest[i] = src[i];
	}
	return (to);
}
