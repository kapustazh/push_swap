/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:48:19 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/08 10:23:12 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*cptr;

	cptr = (unsigned char *)ptr;
	while (len > 0)
	{
		*cptr = (unsigned char)value;
		cptr++;
		len--;
	}
	return (ptr);
}
