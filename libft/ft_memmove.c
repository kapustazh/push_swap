/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:35:16 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/08 10:35:18 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	if (dst < src)
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	else
		while (++i < len)
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
	return (dst);
}
