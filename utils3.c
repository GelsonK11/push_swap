/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:11:51 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/25 16:11:52 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *s)
{
	s->top = NULL;
}

int	is_empty(t_stack *s)
{
	return (s->top == NULL);
}

void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*temp;

	current = s->top;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	s->top = NULL;
}

int	ft_stack_size(t_stack *a)
{
	t_node	*current;
	int		size;

	size = 0;
	current = a->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	*copy_stack_to_array(t_stack **a, int size)
{
	int		*arr;
	t_node	*temp;
	int		i;

	arr = (int *)malloc(size * sizeof(int));
	temp = (*a)->top;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}
