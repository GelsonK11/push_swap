/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:44:25 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/25 09:44:27 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *c, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	pivot = c[end];
	i = (start - 1);
	j = start;
	while (j <= end - 1)
	{
		if (c[j] <= pivot)
		{
			i++;
			swap(&c[i], &c[j]);
		}
		j++;
	}
	swap(&c[i + 1], &c[end]);
	return (i + 1);
}

void	quick_sort(int *c, int start, int end)
{
	int	j;

	if (start < end)
	{
		j = partition(c, start, end);
		quick_sort(c, start, j - 1);
		quick_sort(c, j + 1, end);
	}
}
