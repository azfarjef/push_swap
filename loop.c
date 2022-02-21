/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:23:02 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/21 19:15:55 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	loop_list(t_list *list, t_list *start, int set)
{
	t_list	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (set)
			loop->keep = 0;
		if (loop->index > max_tag)
		{
			max_tag = loop->index;
			count++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}

int	biggest_loop(t_list *start, int set)
{
	t_list	*l;
	int		max;
	int		count;
	t_list	*max_keep;

	max = 0;
	l = start;
	while (l)
	{
		count = loop_list(start, l, 0);
		if (count > max)
		{
			max = count;
			max_keep = l;
		}
		l = l->next;
	}
	if (set)
		loop_list(start, max_keep, 1);
	return (max);
}
