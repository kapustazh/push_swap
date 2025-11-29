/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:50:51 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/29 15:51:19 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
		sort_three(a);
	if (size == 5)
		sort_five(a, b);
	else
		sort_chunks(a, b, size);
}