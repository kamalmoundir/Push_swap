/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:26:05 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/26 16:47:15 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	is_list_numbers(char **str)
{
	int	j;
	int	i;
	int	sign;

	i = 0;
	while (str[i])
	{
		j = 0;
		sign = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' || str[i][j] == '+') && sign == 0)
			{
				j++;
				sign = 1;
			}
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	list_integer_str(char *arg, t_stack *stack)
{
	char	**str;
	int		size;
	int		i;

	str = ft_split(arg, ' ');
	size = size_str(str);
	if (!str || size_str(str) == 0 || !is_list_numbers(str))
		return (write(2, "Error\n", 6), free_str(str), -1);
	stack->a = malloc((size * 2) * sizeof(int));
	if (!stack->a)
		return (write(2, "Error\n", 6), free_str(str), -1);
	stack->size_a = size;
	stack->b = malloc((size * 2) * sizeof(int));
	if (!stack->b)
		return (write(2, "Error\n", 6), free_str(str), -1);
	i = -1;
	while (str[++i])
	{
		if (test_for_maxint(str[i]))
			return (write(2, "Error\n", 6), free_str(str), -1);
		stack->a[i] = ft_atoi(str[i]);
	}
	if (is_double(stack->a, stack->size_a))
		return (write(2, "Error\n", 6), free_str(str), -1);
	return (free_str(str), 0);
}

int	is_integer(char *str)
{
	char	*s;
	int		negative;

	s = str;
	negative = 0;
	if (*s == '-' || *s == '+')
	{
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	list_integer_arguments(int *argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	if (*argc <= 1)
		return (write(2, "Error\n", 6), -1);
	stack->size_a = *argc - 1;
	stack->a = malloc((stack->size_a * 2) * sizeof(int));
	stack->b = malloc((stack->size_a * 2) * sizeof(int));
	if (!stack->a || !stack->b)
		return (write(2, "Error\n", 6), free_stack(stack), -1);
	while (i < *argc)
	{
		if (!is_integer(argv[i]) || test_for_maxint(argv[i]))
			return (write(2, "Error\n", 6), -1);
		else
			stack->a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (is_double(stack->a, stack->size_a))
		return (write(2, "Error\n", 6), -1);
	return (0);
}

int	is_double(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
