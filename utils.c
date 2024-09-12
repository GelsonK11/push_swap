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

int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	long result = 0;

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
		if(!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error();
	return((int)(result * sign));
}

int	ft_checkdup(stack *a)
{
    node *current;
    node *tmp; 

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

void ft_error()
{
	write (1, "Error\n", 6);
	exit(1);
}

int 	ft_stack_size(stack *a)
{
	node *current;
	int 	size = 0;

	current = a->top;

	while(current)
	{
		size++;
		current = current->next;
	}
	return(size);
}

int find_max_index(stack *s)
{
    if (s == NULL || s->top == NULL)
    {
        return -1;
    }

    int max_index = 0;
    int max_value = s->top->data;
    int current_index = 0;
    node *current = s->top;

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

/*int 	ft_target(stack **a, stack **b, int num)
{
	int min_index = find_min_index(a);
	int max_index = find_max_index(b);
	num = (*b->top);

	if ( num > max_index)
	{
		ft_target(a, b, )
	}
	else

}*/