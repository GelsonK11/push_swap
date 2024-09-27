/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:07:09 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/05 14:27:49 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_t_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	return (new);
}

void	push(t_stack **s, int value)
{
	t_node	*new;
	t_node	*ptr;

	new = new_t_node(value);
	if (!new)
		return ;
	if (*s == NULL)
	{
		*s = (t_stack *)malloc(sizeof(t_stack));
		if (!*s)
		{
			free(new);
			return ;
		}
		(*s)->top = NULL;
	}
	if ((*s)->top == NULL)
		(*s)->top = new;
	else
	{
		ptr = (*s)->top;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void	push_front(t_stack **s, int value)
{
	t_node	*new;

	if (!s || !*s)
		return ;
	new = new_t_node(value);
	if (!new)
		return ;
	new->next = (*s)->top;
	(*s)->top = new;
}

int	pop(t_stack *s)
{
	int		value;
	t_node	*top;

	if (is_empty(s))
	{
		return (-1);
	}
	top = s->top;
	value = top->data;
	s->top = top->next;
	free(top);
	return (value);
}

int	is_sorted(t_stack *s)
{
	t_node	*current;

	if (s->top == NULL || s->top->next == NULL)
	{
		return (1);
	}
	current = s->top;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}
