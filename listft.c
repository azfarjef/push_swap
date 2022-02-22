/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:04:42 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:29:14 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	fill_list(t_list **lst, int value, int tag, t_mem *mem)
{
	t_list	*elem;
	t_list	*last;

	last = *lst;
	if (value_in_list(*lst, value))
		exit_error(mem);
	elem = malloc(sizeof(t_list));
	if (!elem)
		exit_error(mem);
	elem->next = NULL;
	elem->next_sort = NULL;
	elem->value = value;
	elem->index = tag;
	if (last == NULL)
	{
		*lst = elem;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = elem;
	last->next_sort = elem;
}

void	swap_top(t_list **mem)
{
	t_list	*tmp;
	t_list	*third;

	if (!*mem || !(*mem)->next)
		return ;
	third = (*mem)->next->next;
	tmp = *mem;
	*mem = (*mem)->next;
	(*mem)->next = tmp;
	tmp->next = third;
}

void	push_top_x_to_y(t_list **x, t_list **y)
{
	t_list	*top;

	if (!*x)
		return ;
	top = *x;
	*x = top->next;
	if (*y)
		top->next = (*y);
	else
		top->next = NULL;
	*y = top;
}

void	last_to_first(t_list **x)
{
	t_list	*last;
	t_list	*prev;

	if (!*x || !(*x)->next)
		return ;
	last = *x;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = (*x);
	*x = last;
	prev->next = NULL;
}

void	first_to_last(t_list **x)
{
	t_list	*top;
	t_list	*tmp;

	if (!*x || !(*x)->next)
		return ;
	top = *x;
	*x = (*x)->next;
	tmp = *x;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
	top->next = NULL;
}
