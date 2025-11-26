/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:50:14 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 15:50:16 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t count)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)ptr;
	i = 0;
	while (i < count)
	{
		if (arr[i] == (unsigned char)c)
			return ((void *)&arr[i]);
		i++;
	}
	return (NULL);
}
