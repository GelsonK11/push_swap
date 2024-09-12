/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:42:48 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/09 11:43:06 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_index(stack *s)
{
    if (s == NULL || s->top == NULL) {
        return -1;
    }

    int min_index = 0;
    int min_value = s->top->data;
    int current_index = 0;
    node *current = s->top;

    while (current != NULL)
    {
        if (current->data < min_value)
        {
            min_value = current->data;
            min_index = current_index;
        }
        current = current->next;
        current_index++;
    }
    return min_index;
}

void	ft_putstr(char *s)
{
	int		i = 0;

	while(s[i])
		write(1, &s[i++], 1);
}

void sort_two(stack **s)
{
    if (*s == NULL || (*s)->top == NULL || (*s)->top->next == NULL)
        return;
    printf("Estou no case two\n");
    node *first = (*s)->top;
    node *second = first->next;

    if (first->data > second->data)
    {
  //  	printf("Estou no aqui\n");
    //	sa(s);
    }
}

void sort_three(stack **s)
{
	if (*s == NULL || (*s)->top == NULL || (*s)->top->next == NULL || (*s)->top->next->next == NULL)
		return;
	node *first = (*s)->top;
	node *second = (*s)->top->next;
	node *third = (*s)->top->next->next;
	if (first->data > second->data && second->data > third->data && first->data > third->data)
	{
		sa(s);
		rra(s);
	}
	if (first->data < second->data && second->data > third->data)
	{
		if (first->data > third->data)
			rra(s);
		else
		{
			sa(s);
			ra(s);
		}
	}
	else if (first->data > second->data && second->data < third->data)
	{
		if (first->data > third->data)
			ra(s);
		else
			sa(s);

	}
}


void	sort_fourth(stack **a, stack **b)
{
	if (*a == NULL || (*a)->top == NULL || (*a)->top->next == NULL
			|| (*a)->top->next->next == NULL || (*a)->top->next->next->next == NULL)
		return;
	int	min_index = find_min_index(*a);
	if (min_index == 1)
	{
		sa(a);
	}
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
	{
		rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void sort_fifth(stack **a, stack **b)
{
	if (*a == NULL || (*a)->top == NULL || (*a)->top->next == NULL
			|| (*a)->top->next->next == NULL || (*a)->top->next->next->next == NULL || (*a)->top->next->next->next->next == NULL)
		return;

	int	min_index = find_min_index(*a);
	if (min_index == 1)
	{
		sa(a);
	}
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
	{
		rra(a);
	}
	pb(a, b);
	sort_fourth(a, b);
	pa(a, b);
}