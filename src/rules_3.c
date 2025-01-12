/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:44:24 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/17 18:17:14 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	rotate_a(t_stack *stack, int bonus)
{
	int	tmp;
	int	i;

	tmp = stack->a[0];
	i = 0;
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = tmp;
	if (!bonus)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack, int bonus)
{
	int	tmp;
	int	i;

	tmp = stack->b[0];
	i = 0;
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = tmp;
	if (!bonus)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_stack *stack, int bonus)
{
	rotate_a(stack, 1);
	rotate_b(stack, 1);
	if (!bonus)
		write(1, "rr\n", 3);
}
