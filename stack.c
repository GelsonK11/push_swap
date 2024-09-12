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

void	init(stack *s)
{
	s->top = NULL;
}

int	is_Empty(stack *s)
{
	return(s->top == NULL);
}

node *new_node(int value)
{
    node *new = malloc(sizeof(node));
    if (!new)
        return NULL;
    new->data = value;
    new->next = NULL;
    return new;
}

void push(stack *s, int value)
{
    node *new = new_node(value);
    if (!new)
    {
        printf("Erro ao alocar memória para um novo nó.\n");
        return;
    }

    new->next = s->top;
    s->top = new;
}

void	print_stack(stack *s)
{
	node *current = s->top;
	while(current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
    }
    //ft_putstr("sa");
	printf("\n");
}

void free_stack(stack *s)
{
	node *current = s->top;
	while (current != NULL)
	{
		node *temp = current;
		current = current->next;
		free(temp);
	}
	s->top = NULL;
}

int peek(stack *s)
{
    if (is_Empty(s))
    {
        printf("Erro: a pilha está vazia.\n");
        return (-1);
    }
    return s->top->data;
}

int pop(stack *s)
{
    if (is_Empty(s))
    {
        printf("A pilha está vazia, não é possível fazer pop\n");
        return -1;
    }

    node *top = s->top;
    int value = top->data;
    s->top = top->next;
    free(top);
    return value;
}

int is_sorted(stack *s)
{
    if (s->top == NULL || s->top->next == NULL)
        return 1;

    node *current = s->top;

    while (current->next != NULL)
    {
        if (current->data < current->next->data)
            return (0);
        current = current->next;
    }

    return (1);
}