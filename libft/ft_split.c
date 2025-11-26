/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:48:47 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 15:48:51 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_counter(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] && str[i] != c)
			{
				i++;
				if (str[i] == '\0')
					return (word);
			}
		}
		else
			i++;
	}
	return (word);
}

static char	*word_split(const char *str, char c)
{
	int		length;
	char	*word;
	int		i;

	length = 0;
	i = 0;
	while (str[length] && str[length] != c)
		length++;
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_words(char **words, size_t j)
{
	while (j > 0)
	{
		j--;
		free(words[j]);
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**words;

	j = 0;
	i = 0;
	words = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!s || !words)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = word_split(&s[i], c);
			if (!words[j])
				return (free_words(words, j));
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (words);
}
