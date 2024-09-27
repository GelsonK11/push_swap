/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:53:26 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/06 13:53:28 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		result = result * 10 + (str[i++] - '0');
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error();
	return ((int)(result * sign));
}

int	ft_checkdup(t_stack *a)
{
	t_node	*current;
	t_node	*tmp;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_error(void)
{
	write (1, "Error\n", 6);
	exit(1);
}

int	find_max_index(t_stack *s)
{
	int		max_index;
	int		max_value;
	int		current_index;
	t_node	*current;

	if (s == NULL || s->top == NULL)
		return (-1);
	max_index = 0;
	max_value = s->top->data;
	current_index = 0;
	current = s->top;
	while (current != NULL)
	{
		if (current->data > max_value)
		{
			max_value = current->data;
			max_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (max_index);
}

int	find_min_index(t_stack *s)
{
	int		min_index;
	int		min_value;
	int		current_index;
	t_node	*current;

	if (s == NULL || s->top == NULL)
		return (-1);
	min_index = 0;
	min_value = s->top->data;
	current_index = 0;
	current = s->top;
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
	return (min_index);
}
