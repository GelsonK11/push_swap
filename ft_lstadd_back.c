/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <gkiala@student.42luanda.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:26:14 by gkiala            #+#    #+#             */
/*   Updated: 2024/05/20 17:26:19 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}
