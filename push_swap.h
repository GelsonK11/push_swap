/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:33:06 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/06 08:33:08 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node
{
    int data;      // Membro existente para dados do nó
    //int index;     // Membro adicionado para o índice
    struct s_node *next;
} node;

typedef struct
{
    node *top;  // Ponteiro para o topo da pilha (lista encadeada)
} stack;

void	push(stack *s, int value);
void	print_stack(stack *s);
void	init(stack *s);
int		peek(stack *s);
int		is_Empty(stack *s);
int		pop(stack *s);
int		ft_atoi(char *str);
int	is_sorted(stack *s);
void	free_stack(stack *s);
void	sa(stack **a);
void	sb(stack **b);
void	ss(stack **a, stack **b);
void	pa(stack **a, stack **b);
void	pb(stack **a, stack **b);
void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);
void	rra(stack **a);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);
void	sort_three(stack **a);
void	sort_two(stack **a);
void	sort_fourth(stack **a, stack **b);
void sort_fifth(stack **a, stack **b);
void ft_error();
int	ft_checkdup(stack *a);
int 	ft_stack_size(stack *a);
void radix_sort(stack **a, stack **b);
void	ft_putstr(char *s);


#endif