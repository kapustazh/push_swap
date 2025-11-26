/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#             */
/*   Updated: 2025/11/26 22:22:37 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*find_max_index(t_stack **a)
{
	int		max;
	int		max_idx;
	t_stack	*node;
	t_stack	*current;

	if (!a || !*a)
		return (NULL);
	max = INT_MIN;
	max_idx = INT_MIN;
	node = NULL;
	current = *a;
	while (current)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
			node = current;
		}
		current = current->next;
	}
	return (node);
}

void	sort_three_elem(t_stack **a)
{
	t_stack	*max;

	max = find_max_index(a);
	if ((*a)->index == max->index)
		ra(a);
	else if ((*a)->next->index == max->index)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static int	calc_sqrt(int num)
{
	long	val;

	val = 0;
	if (num < 1)
		return (0);
	while (val * val < (long)num)
		val++;
	if (val * val == (long)num)
		return (val);
	return ((int)val - 1);
}

static void	divide_chunks(t_stack **a, t_stack **b, int size)
{
	int	counter;
	int	chunk_size;

	counter = 0;
	chunk_size = calc_sqrt(size) * 14 / 10;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b);
			if (*a && ((*a)->index <= counter
					|| (*a)->index <= counter + chunk_size))
				rb(b);
			else
				rr(a, b);
			counter++;
		}
		else if ((*a)->index <= counter + chunk_size)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

static int	count_rotations(t_stack *stack, int size)
{
	int	rotations;

	rotations = 0;
	while (stack && stack->index != (size - 1))
	{
		rotations++;
		stack = stack->next;
	}
	return (rotations);
}

void	sort_chunks(t_stack **a, t_stack **b, int size)
{
	int	rot;
	int	rev_rot;

	divide_chunks(a, b, size);
	while (size - 1 >= 0)
	{
		rot = count_rotations(*b, size);
		rev_rot = size - rot;
		if (rot <= rev_rot)
		{
			while ((*b)->index != size - 1)
				rb(b);
			pa(a, b);
			size--;
		}
		else
		{
			while ((*b)->index != size - 1)
				rrb(b);
			pa(a, b);
			size--;
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (check_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three_elem(a);
	else
		sort_chunks(a, b, size);
}
