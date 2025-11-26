/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:47:44 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 15:47:48 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = ft_strdup(s);
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		temp[i] = f(i, temp[i]);
		i++;
	}
	return (temp);
}
