/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:50:20 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:30:19 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The number of elements in the list.
 */
int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
