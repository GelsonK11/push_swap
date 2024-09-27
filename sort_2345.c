/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:42:48 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/09 11:43:06 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	t_node	*first;
	t_node	*second;

	first = (*a)->top;
	second = (*a)->top->next;
	if (first->data > second->data)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int		max_index;
	t_node	*first;
	t_node	*second;

	first = (*a)->top;
	second = (*a)->top->next;
	max_index = find_max_index(*a);
	if (max_index == 0)
	{
		ra(a);
		first = (*a)->top;
		second = (*a)->top->next;
	}
	else if (max_index == 1)
	{
		rra(a);
		first = (*a)->top;
		second = (*a)->top->next;
	}
	if (first->data > second->data)
		sa(a);
}

void	sort_fourth(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_fifth(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_index == 4)
		rra(a);
	pb(a, b);
	sort_fourth(a, b);
	pa(a, b);
}
