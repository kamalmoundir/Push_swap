/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_shunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:30:23 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/16 22:55:07 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	push_return_len(t_stack *stack, int len, int i)
{
	if (i == 0)
	{
		push_a(stack, 0);
		len--;
	}
	else
	{
		push_b(stack, 0);
		len--;
	}
	return (len);
}

void	quicksort_three_stack_a_and_b(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				swap_a(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = push_return_len(stack, len, 1);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack, 0);
			else if (len++)
				push_a(stack, 0);
		}
	}
}

int	quicksort_a(t_stack *stack, int len, int count)
{
	int	pivot;
	int	size;

	if (stack_is_sorted(stack->a, len))
		return (1);
	size = len;
	if (len <= 3)
		return (quicksort_three_stack_a_and_b(stack, len), 1);
	the_median(stack->a, len, &pivot);
	while (len != size / 2 + size % 2 && below_median(stack->a, len, pivot))
	{
		if (stack->a[0] < pivot && len--)
			push_b(stack, 0);
		else if (++count)
			rotate_a(stack, 0);
	}
	while (size / 2 + size % 2 != stack->size_a && count--)
		reverse_rotate_a(stack, 0);
	return (quicksort_a(stack, size / 2 + size % 2, 0) && quicksort_b(stack,
			size / 2, 0));
}

int	sort_three_b2(t_stack *stack, int len)
{
	if (len == 1)
		push_a(stack, 0);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			swap_b(stack, 0);
		while (len--)
			push_a(stack, 0);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				swap_a(stack, 0);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = push_return_len(stack, len, 0);
			else
				swap_b(stack, 0);
		}
	}
	return (0);
}

int	quicksort_b(t_stack *stack, int len, int count)
{
	int	pivot;
	int	size;

	pivot = 0;
	if (len <= 0)
		return (0);
	if (stack_is_sorted_reverse(stack->b, len))
		while (len--)
			push_a(stack, 0);
	if (len <= 3)
		return (sort_three_b2(stack, len), 1);
	size = len;
	if (!the_median(stack->b, len, &pivot))
		return (0);
	while (len >= size / 2 && upper_median(stack->b, len, pivot))
	{
		if (stack->b[0] >= pivot && len--)
			push_a(stack, 0);
		else if (++count)
			rotate_b(stack, 0);
	}
	while (size / 2 != stack->size_b && count--)
		reverse_rotate_b(stack, 0);
	return (quicksort_a(stack, size / 2 + size % 2, 0) && quicksort_b(stack,
			size / 2, 0));
}
