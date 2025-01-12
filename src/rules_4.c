/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:21:35 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/17 18:16:38 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	reverse_rotate_a(t_stack *stack, int bonus)
{
	int	tmp;
	int	i;

	tmp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i >= 0)
	{
		stack->a[i + 1] = stack->a[i];
		i--;
	}
	stack->a[0] = tmp;
	if (!bonus)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack, int bonus)
{
	int	tmp;
	int	i;

	tmp = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i >= 0)
	{
		stack->b[i + 1] = stack->b[i];
		i--;
	}
	stack->b[0] = tmp;
	if (!bonus)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(t_stack *stack, int bonus)
{
	reverse_rotate_a(stack, 1);
	reverse_rotate_b(stack, 1);
	if (!bonus)
		write(1, "rrr\n", 4);
}
