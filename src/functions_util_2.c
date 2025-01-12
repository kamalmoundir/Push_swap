/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:38:33 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/26 16:47:56 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap.h"

int	upper_median(int *array, int size, int pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] >= pivot)
			return (1);
		i++;
	}
	return (0);
}

int	below_median(int *array, int size, int pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

int	the_median(int *array, int size, int *pivot)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(size * sizeof(int));
	i = 0;
	if (!tmp)
		return (0);
	while (i < size)
	{
		tmp[i] = array[i];
		i++;
	}
	sort_temp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}

void	sort_temp(int *array, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	if (size >= 2)
	{
		while (i < size)
		{
			j = i + 1;
			while (j < size)
			{
				if (array[i] > array[j])
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
				j++;
			}
			i++;
		}
	}
}

int	test_for_maxint(char *str)
{
	if (ft_strncmp(str, "-1", ft_strlen(str)) != 0 && ft_atoi(str) == -1)
		return (1);
	return (0);
}
