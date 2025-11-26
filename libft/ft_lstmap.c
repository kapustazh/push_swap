/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:17:36 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/08 20:20:47 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	ptr = f(lst->content);
	new = ft_lstnew(ptr);
	if (!new)
		return (del(ptr), NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		ptr = f(lst->content);
		tmp->next = ft_lstnew(ptr);
		if (!tmp->next)
			return (ft_lstclear(&new, del), del(ptr), NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
