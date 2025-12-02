/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:50:51 by mnestere          #+#    #+#             */
/*   Updated: 2025/12/02 18:22:07 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, int size, t_stack **result)
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
