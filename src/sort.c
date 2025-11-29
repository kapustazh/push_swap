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

void	set_index(t_stack *stack_a)
{
	t_stack	*ptr;
	t_stack	*highest;
	long		value;
	int			s_size;

	s_size = stack_len(stack_a);
	while (--s_size >= 0)
	{
		ptr = stack_a;
		highest = NULL;
		value = LONG_MIN;
		while (ptr)
		{
			if (ptr->index == 0 && (long)ptr->value >= value)
			{
				value = ptr->value;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest == NULL)
			break;
		highest->index = s_size;
	}
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
	if (size <= 3)
		sort_three(a);
	else
		sort_chunks(a, b, size);
}