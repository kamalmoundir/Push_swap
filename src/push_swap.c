/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:32:40 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/17 17:52:43 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac >= 2)
	{
		stack = malloc(sizeof(t_stack));
		stack->size_a = 0;
		stack->size_b = 0;
		stack->a = NULL;
		stack->b = NULL;
		if (!stack)
			return (1);
		if (ac == 2)
		{
			if (list_integer_str(av[1], stack) == -1)
				return (free_stack(stack), 1);
		}
		else if (ac > 2)
		{
			if (list_integer_arguments(&ac, av, stack) == -1)
				return (free_stack(stack), 1);
		}
		quicksort_a(stack, stack->size_a, 0);
		free_stack(stack);
	}
	return (0);
}
