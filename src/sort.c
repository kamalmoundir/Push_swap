/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:59:08 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/16 20:01:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

void	sort_three_a(t_stack *st)
{
	if (st->a[2] > st->a[1] && st->a[2] > st->a[0] && st->a[0] > st->a[1])
		swap_a(st, 0);
	else if (st->a[0] > st->a[1] && st->a[1] > st->a[2])
	{
		swap_a(st, 0);
		reverse_rotate_a(st, 0);
	}
	else if (st->a[0] > st->a[1] && st->a[0] > st->a[2] && st->a[1] < st->a[2])
		rotate_a(st, 0);
	else if (st->a[0] < st->a[1] && st->a[0] < st->a[2] && st->a[1] > st->a[2])
	{
		swap_a(st, 0);
		rotate_a(st, 0);
	}
	else if (st->a[0] < st->a[1] && st->a[0] > st->a[2] && st->a[1] > st->a[2])
		reverse_rotate_a(st, 0);
}

void	sort_three_b(t_stack *st)
{
	if (st->b[2] < st->b[1] && st->b[2] < st->b[0] && st->b[0] < st->b[1])
		swap_b(st, 0);
	else if (st->b[0] < st->b[1] && st->b[1] < st->b[2])
	{
		swap_b(st, 0);
		reverse_rotate_b(st, 0);
	}
	else if (st->b[0] < st->b[1] && st->b[0] < st->b[2] && st->b[1] > st->b[2])
		rotate_b(st, 0);
	else if (st->b[0] > st->b[1] && st->b[0] > st->b[2] && st->b[1] < st->b[2])
	{
		swap_b(st, 0);
		rotate_b(st, 0);
	}
	else if (st->b[0] > st->b[1] && st->b[0] < st->b[2] && st->b[1] < st->b[2])
		reverse_rotate_b(st, 0);
}

void	sort_two_a(t_stack *st)
{
	if (st->a[0] > st->a[1])
		swap_a(st, 0);
}

void	sort_two_b(t_stack *st)
{
	if (st->b[0] < st->b[1])
		swap_b(st, 0);
}
