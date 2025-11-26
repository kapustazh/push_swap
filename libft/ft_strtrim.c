/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:47:17 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:59:13 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

/**
 * @brief Trims specified characters from the beginning and end of a string.
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim.
 * @return The newly allocated trimmed string, or NULL if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start;
	char	*end;
	size_t	len;

	if (!set || !*s1)
		return (ft_strdup(""));
	start = (char *)s1;
	while (*start && is_sep(*start, set))
		start++;
	if (!*start)
		return (ft_strdup(""));
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (end > start && is_sep(*end, set))
		end--;
	len = end - start + 1;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (len--)
		result[len] = start[len];
	result[end - start + 1] = '\0';
	return (result);
}
