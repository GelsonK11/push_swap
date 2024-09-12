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

void ra(stack **a)
{
    if (is_Empty(*a) || (*a)->top->next == NULL)
        return;

    node *first = (*a)->top;
    (*a)->top = (*a)->top->next;
    first->next = NULL;

    node *current = (*a)->top;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = first;
}

void rb(stack **b)
{
    if (is_Empty(*b) || (*b)->top->next == NULL)
        return;

    node *first = (*b)->top;
    (*b)->top = (*b)->top->next;
    first->next = NULL;

    node *current = (*b)->top;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = first;
}


void rr(stack **a, stack **b)
{
    ra(a);
    rb(b);
}