/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:48:02 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/06 10:48:04 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_node	*current;
	t_node	*first;

	if (is_empty(*a) || (*a)->top->next == NULL)
		return ;
	first = (*a)->top;
	(*a)->top = (*a)->top->next;
	first->next = NULL;
	current = (*a)->top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	write (1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_node	*current;
	t_node	*first;

	if (is_empty(*b) || (*b)->top->next == NULL)
		return ;
	first = (*b)->top;
	(*b)->top = (*b)->top->next;
	first->next = NULL;
	current = (*b)->top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	write (1, "rb\n", 3);
}

void	rra(t_stack **a)
{
	t_node	*current;
	t_node	*prev;

	if (is_empty(*a) || (*a)->top->next == NULL)
		return ;
	current = (*a)->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = (*a)->top;
	(*a)->top = current;
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_node	*current;
	t_node	*prev;

	if (is_empty(*b) || (*b)->top->next == NULL)
		return ;
	current = (*b)->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = (*b)->top;
	(*b)->top = current;
	write (1, "rrb\n", 3);
}
