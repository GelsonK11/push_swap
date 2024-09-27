/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:25:17 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/09 11:25:38 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	map_stack_to_sorted_indices(t_stack **a, int *sorted, int size)
{
	t_node	*temp;
	int		i;

	temp = (*a)->top;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->data == sorted[i])
			{
				temp->data = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	map_to_indices(t_stack **a, int size)
{
	int		*arr;
	int		*sorted;
	int		i;

	arr = copy_stack_to_array(a, size);
	sorted = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort(sorted, 0, size - 1);
	map_stack_to_sorted_indices(a, sorted, size);
	free(arr);
	free(sorted);
}

int	calculate_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_by_bit(t_stack **a, t_stack **b, int bit, int size)
{
	t_node	*temp;
	int		num;
	int		j;

	j = 0;
	while (j < size)
	{
		temp = (*a)->top;
		num = temp->data;
		if (((num >> bit) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while ((*b)->top)
		pa(a, b);
}

void	sort_big_stack(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	max_bits;

	map_to_indices(a, size);
	max_bits = calculate_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		sort_by_bit(a, b, i, size);
		i++;
	}
}
