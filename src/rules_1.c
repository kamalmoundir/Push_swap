/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:23:19 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/17 19:42:37 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_a(t_stack *stack, int bonus)
{
	if (stack->size_a > 1)
		ft_swap(stack->a, stack->a + 1);
	if (!bonus)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack, int bonus)
{
	if (stack->size_b > 1)
		ft_swap(stack->b, stack->b + 1);
	if (!bonus)
		write(1, "sb\n", 3);
}

void	swap_ss(t_stack *stack, int bonus)
{
	ft_swap(stack->a, stack->a + 1);
	ft_swap(stack->b, stack->b + 1);
	if (!bonus)
		write(1, "ss\n", 3);
}
