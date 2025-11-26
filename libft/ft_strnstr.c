/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:47:31 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 13:02:19 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locates a substring within a string, searching up to a specific length
 * @param big The string to search in.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search in hayastack
 * @return A pointer to the beginning of the located substring or NULL
 */
char	*ft_strnstr(const char *haystick, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystick);
	i = 0;
	while (haystick[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len && haystick[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystick + i);
		i++;
	}
	return (NULL);
}
