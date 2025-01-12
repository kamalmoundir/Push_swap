/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:33:12 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/17 18:14:34 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	push_a(t_stack *stack, int bonus)
{
	int	i;
	int	j;

	if (stack->size_b > 0)
	{
		i = stack->size_a;
		stack->size_a += 1;
		while (i >= 0)
		{
			stack->a[i + 1] = stack->a[i];
			i--;
		}
		stack->a[0] = stack->b[0];
		j = 0;
		stack->size_b -= 1;
		while (j < stack->size_b)
		{
			stack->b[j] = stack->b[j + 1];
			j++;
		}
		if (!bonus)
			write(1, "pa\n", 3);
	}
	else
		return ;
}

void	push_b(t_stack *stack, int bonus)
{
	int	i;
	int	j;

	if (stack->size_a > 0)
	{
		i = stack->size_b;
		stack->size_b += 1;
		while (i >= 0)
		{
			stack->b[i + 1] = stack->b[i];
			i--;
		}
		stack->b[0] = stack->a[0];
		j = 0;
		stack->size_a -= 1;
		while (j < stack->size_a)
		{
			stack->a[j] = stack->a[j + 1];
			j++;
		}
		if (!bonus)
			write(1, "pb\n", 3);
	}
	else
		return ;
}
