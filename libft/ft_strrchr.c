/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:47:25 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 13:02:21 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Finds the last occurrence of a character in a string.
 * @param str The string to search in.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of the character or NULL
 */
char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			last = (char *)&str[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (last);
}
