/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:03:31 by gkiala            #+#    #+#             */
/*   Updated: 2024/08/22 14:17:15 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct snode
{
	int	val;
	struct snode *next;
}	sNode;

typedef struct linked_list
{
	sNode *begin;
}	Linkedlist;
