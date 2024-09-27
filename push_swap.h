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

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void	push(t_stack **s, int value);
void	push_front(t_stack **s, int value);
void	init(t_stack *s);
void	free_stack(t_stack *s);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_two(t_stack **a);
void	sort_fourth(t_stack **a, t_stack **b);
void	sort_fifth(t_stack **a, t_stack **b);
void	ft_error(void);
int		is_empty(t_stack *s);
int		pop(t_stack *s);
int		ft_atoi(char *str);
int		is_sorted(t_stack *s);
int		ft_checkdup(t_stack *a);
int		ft_stack_size(t_stack *a);
int		find_max_index(t_stack *s);
int		find_min_index(t_stack *s);
int		calculate_max_bits(int size);
int		partition(int arr[], int low, int high);
int		*copy_stack_to_array(t_stack **a, int size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);
void	map_stack_to_sorted_indices(t_stack **a, int *sorted, int size);
void	map_to_indices(t_stack **a, int size);
void	sort_big_stack(t_stack **a, t_stack **b, int size);
void	sort_by_bit(t_stack **a, t_stack **b, int bit, int size);
void	swap(int *a, int *b);
void	quick_sort(int arr[], int low, int high);
void	handle_sorting(t_stack **a, t_stack **b, int num);
void	free_resources(t_stack *a, t_stack *b, char **args, int argc);
void	initialize_stacks(t_stack **a, t_stack **b);

#endif
