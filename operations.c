/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:27:02 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/05 14:27:03 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_node	*first;
	t_node	*second;

	first = (*a)->top;
	second = (*a)->top->next;
	if (is_empty(*a) || (*a)->top->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	(*a)->top = second;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	int	value;

	if (!is_empty(*b))
	{
		value = pop(*b);
		push_front(a, value);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	int	value;

	if (!is_empty(*a))
	{
		value = pop(*a);
		push_front(b, value);
		write(1, "pb\n", 3);
	}
}
