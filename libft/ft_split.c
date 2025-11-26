/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:09:16 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/08 18:15:53 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			words++;
		while (*str && *str != c)
			str++;
	}
	return (words);
}

static const char	*ft_add_word(char **res, int i, char const *s, char c)
{
	char const	*next;

	while (*s == c)
		s++;
	next = ft_strchr(s, c);
	if (!next)
		next = s + ft_strlen(s);
	res[i] = ft_substr(s, 0, next - s);
	if (!res[i])
		return (NULL);
	return (next);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		s = ft_add_word(res, i, s, c);
		if (!s)
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
	}
	res[words] = NULL;
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	char	**split;
// 	const char	*s ="Hello World! How are you?";
// 	char	c = ' ';
// 	int i;
// 	i = 0;
// 	// printf("Words: %d\n", ft_wordcount(s, c));
// 	split = ft_split(s, c);
// 	while(split[i])
// 	{
// 		printf("%d: \"%s\"\n",i, split[i]);
// 		i++;
// 	}
// 	return (0);
// }
