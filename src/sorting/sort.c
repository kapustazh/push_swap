/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:50:51 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/30 20:09:05 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, int size, t_list **result)
{
	if (check_sorted(*a))
		return ;
	else if (size <= 3)
		sort_three(a, result);
	else if (size == 5)
		sort_five(a, b, result);
	else
		sort_chunks(a, b, size, result);
}
