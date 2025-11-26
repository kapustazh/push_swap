/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:50:29 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/13 12:34:18 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Creates a new list by applying a function to each element of an old
 * @param lst The beginning of the original list.
 * @param f The function to apply to each element's content.
 * @param del A function pointer used to delete content on allocation failure.
 * @return The new list, or NULL if an allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
