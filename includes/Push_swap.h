/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:16:49 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/26 16:00:57 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

void	swap_a(t_stack *stack, int bonus);
void	swap_b(t_stack *stack, int bonus);
void	swap_ss(t_stack *stack, int bonus);

void	push_a(t_stack *stack, int bonus);
void	push_b(t_stack *stack, int bonus);

void	rotate_a(t_stack *stack, int bonus);
void	rotate_b(t_stack *stack, int bonus);
void	rotate_rr(t_stack *stack, int bonus);

void	reverse_rotate_a(t_stack *stack, int bonus);
void	reverse_rotate_b(t_stack *stack, int bonus);
void	reverse_rotate_rr(t_stack *stack, int bonus);

int		list_integer_str(char *arg, t_stack *stack);
int		ft_atoi(const char *nptr);
int		list_integer_arguments(int *argc, char **argv, t_stack *stack);
int		is_integer(char *str);
int		is_list_numbers(char **str);
int		is_double(int *a, int size);
int		stack_is_sorted(int *tab, int size);
int		stack_is_sorted_reverse(int *tab, int size);
int		size_str(char **str);
int 	test_for_maxint(char *str);

void	sort_three_a(t_stack *stack);
void	sort_three_b(t_stack *stack);
void	sort_two_a(t_stack *st);
void	sort_two_b(t_stack *st);
int		quicksort_a(t_stack *stack, int len, int count);
int		quicksort_b(t_stack *stack, int len, int count);
void	free_stack(t_stack *stack);
int		below_median(int *array, int size, int pivot);
int		the_median(int *array, int size, int *pivot);
int		upper_median(int *array, int size, int pivot);
void	sort_temp(int *array, int size);
void	free_str(char **str);
#endif