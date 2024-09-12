/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:42:06 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/06 13:42:08 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("error : %s <argumentos inválidos>\n", argv[0]);
		return(1);
	}
    stack *a = malloc(sizeof(stack));
    stack *b = malloc(sizeof(stack));
    
    init(a);
    init(b);

    int num = argc - 1;

    if (argc > 2)
    {
    	int i = 1;
    	while(argv[i])
    	{
    		push(a, ft_atoi(argv[i]));
    		i++;
    	}

    	if (ft_checkdup(a))
		{
			ft_error();
			free_stack(a);
			free_stack(b);
			free(a);
			free(b);
		}

    	if (is_sorted(a) == 1)
    	{
    		free_stack(a);
    		free_stack(b);
    		free(a);
    		free(b);
    		exit(0);
    		return(0);
    	}
    	else
    	{

	    	if (num == 2)
	    	{
	    		sort_two(&a);
	    		print_stack(a);
	    	}
		
		    if (num  == 3)
		    {
		    	sort_three(&a);
		    	print_stack(a);
	    	}
	    	if (num == 4)
	    	{
	    		sort_fourth(&a, &b);
	    		print_stack(a);
	    	}
	    	if (num == 5)
	    	{
	    		sort_fifth(&a, &b);
	    		print_stack(a);
	    	}
	    	/*else
	    	{
	    		radix_sort(&a, &b);
	    		print_stack(a);
	    	}*/
	    }
    }
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);
    
    return 0;
}

