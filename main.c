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

#include  "push_swap.h"

void	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		ft_error();
		exit(1);
	}
	(*a)->top = NULL;
	(*b)->top = NULL;
}

void	free_resources(t_stack *a, t_stack *b, char **args, int argc)
{
	int	j;

	if (argc == 2)
	{
		j = 0;
		while (args[j])
		{
			free(args[j]);
			j++;
		}
		free(args);
	}
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}

int	validate_arguments(int argc, char *argv[], char ***args)
{
	if (argc < 2)
	{
		ft_printf("error: %s <argumentos inválidos>\n", argv[0]);
		return (1);
	}
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
	}
	else
		*args = argv + 1;
	return (0);
}

void	handle_sorting(t_stack **a, t_stack **b, int num)
{
	if (num == 2)
		sort_two(a);
	else if (num == 3)
		sort_three(a);
	else if (num == 4)
		sort_fourth(a, b);
	else if (num == 5)
		sort_fifth(a, b);
	else
		sort_big_stack(a, b, num);
}

int	main(int argc, char *argv[])
{
	char	**args;
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (validate_arguments(argc, argv, &args))
		return (1);
	initialize_stacks(&a, &b);
	i = 0;
	while (args[i])
	{
		push(&a, ft_atoi(args[i]));
		i++;
	}
	if (ft_checkdup(a))
	{
		ft_error();
		free_resources(a, b, args, argc);
		return (1);
	}
	if (!is_sorted(a))
		handle_sorting(&a, &b, i);
	free_resources(a, b, args, argc);
	return (0);
}
