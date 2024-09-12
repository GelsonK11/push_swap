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

void sa(stack **a)
{
    if (is_Empty(*a) || (*a)->top->next == NULL)
    {
        printf("Não é possível trocar elementos: a pilha está vazia ou tem menos de dois elementos\n");
        return;
    }

    node *first = (*a)->top;
    node *second = (*a)->top->next;

    first->next = second->next;
    second->next = first;
    (*a)->top = second;
    printf("sa\n");
}


void sb(stack **b)
{
    if (is_Empty(*b) || (*b)->top->next == NULL)
    {
        printf("Não é possível trocar elementos: a pilha está vazia ou tem menos de dois elementos\n");
        return;
    }

    node *first = (*b)->top;
    node *second = (*b)->top->next;

    first->next = second->next;
    second->next = first;
    (*b)->top = second; 
}

void ss(stack **a, stack **b)
{
	sa(a);
	sb(b);
}

void pa(stack **a, stack **b)
{
    if (!is_Empty(*b))
    {
        int value = pop(*b);
        push(*a, value);
    }
}


void pb(stack **a, stack **b)
{
    if (!is_Empty(*a))
    {
        int value = pop(*a);
        push(*b, value);
    }
}
