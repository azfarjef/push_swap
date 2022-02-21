/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:31:35 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/18 16:47:11 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	value_in_list(t_list *lst, int value)
{
	while (lst)
	{
		if (lst->value == value)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	is_ordered(t_mem *mem)
{
	t_list	*l;
	int		prev;

	if (mem->b)
		return (0);
	if (!mem->a)
		return (1);
	l = mem->a;
	prev = l->value;
	while (l)
	{
		if (prev > l->value)
			return (0);
		prev = l->value;
		l = l->next;
	}
	return (1);
}

void	swap_list(t_list **keep, t_list *two)
{
	t_list	*tmp;

	tmp = *keep;
	*keep = two->next_sort;
	tmp->next_sort = two->next_sort->next_sort;
	(*keep)->next_sort = tmp;
}

void	sort_list(t_list **tagged)
{
	t_list	*one;
	t_list	*two;

	one = NULL;
	two = *tagged;
	while (two && two->next_sort)
	{
		if (two->value - two->next_sort->value > 0)
		{
			if (one == NULL)
				swap_list(tagged, two);
			else
				swap_list(&(one->next_sort), two);
			two = *tagged;
			one = NULL;
		}
		else
		{
			one = two;
			two = two->next_sort;
		}
	}
}

void	tag_list(t_list *list, t_mem *mem)
{
	int	i;

	i = 0;
	while (list)
	{
		list->index = i++;
		list = list->next_sort;
	}
	mem->max = i;
}