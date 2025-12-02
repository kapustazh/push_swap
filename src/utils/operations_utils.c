/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:10:38 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/02 18:25:10 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	record_operation(t_stack **result, const char *op)
{
	t_stack	*node;
	char	*dup;

	if (!result || !op)
		return ;
	dup = ft_strdup(op);
	if (!dup)
		error_exit(NULL, NULL);
	node = ft_lstnew(dup);
	if (!node)
	{
		free(dup);
		error_exit(NULL, NULL);
	}
	ft_lstadd_back(result, node);
}

static int	print_pair(char *cur, char *next)
{
	if (!cur || !next)
		return (0);
	if (ft_strncmp(cur, "rra", 4) == 0 && ft_strncmp(next, "rrb", 4) == 0)
	{
		ft_putendl_fd("rrr", 1);
		return (1);
	}
	if (ft_strncmp(cur, "ra", 3) == 0 && ft_strncmp(next, "rb", 3) == 0)
	{
		ft_putendl_fd("rr", 1);
		return (1);
	}
	if (ft_strncmp(cur, "sa", 3) == 0 && ft_strncmp(next, "sb", 3) == 0)
	{
		ft_putendl_fd("ss", 1);
		return (1);
	}
	return (0);
}

void	print_operations(t_stack *operations)
{
	char	*cur;
	char	*next;

	while (operations)
	{
		cur = (char *)operations->value;
		next = NULL;
		if (operations->next)
			next = (char *)operations->next->value;
		if (print_pair(cur, next))
			operations = operations->next->next;
		else
		{
			ft_putendl_fd(cur, 1);
			operations = operations->next;
		}
	}
}
