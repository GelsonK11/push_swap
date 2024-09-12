/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algoritm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:25:17 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/09 11:25:38 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(stack **s)  // Pilha como ponteiro para ponteiro
{
    node *head;
    int max;
    int max_bits;

    head = (*s)->top;  // Acessa o topo da pilha através do ponteiro para ponteiro
    max = head->data;  // Acessa o índice do primeiro nó
    max_bits = 0;
    while (head)  // Percorre os nós na pilha
    {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix_sort(stack **a, stack **b)
{
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    size = ft_stack_size(*a);
    max_bits = get_max_bits(a);
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            //printf("Top data: %d, Bit %d: %d\n", (*a)->top->data, i, (((*a)->top->data >> i) & 1));
            if ((((*a)->top->data >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (ft_stack_size(*b) != 0)
            pa(a, b);
        i++;
    }
}



