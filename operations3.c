/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:07:45 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/06 11:07:56 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(stack **a)
{
    if (is_Empty(*a) || (*a)->top->next == NULL)
        return;

    node *current = (*a)->top;
    node *prev = NULL;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }


    prev->next = NULL;
    current->next = (*a)->top;
    (*a)->top = current;
}

void rrb(stack **b)
{
    if (is_Empty(*b) || (*b)->top->next == NULL)
        return;

    node *current = (*b)->top;
    node *prev = NULL;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = (*b)->top;
    (*b)->top = current;
}


void rrr(stack **a, stack **b)
{
    rra(a);
    rrb(b);
}