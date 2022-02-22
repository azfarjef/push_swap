/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:54:22 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:24:22 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	has_tag(t_list *list, int tag)
{
	while (list)
	{
		if (list->index == tag)
			return (1);
		list = list->next;
	}
	return (0);
}

void	prep_five(t_mem *mem)
{
	t_list	*l;
	int		min;
	int		now;

	while (has_tag(mem->a, 0) || has_tag(mem->a, mem->max - 1))
	{
		l = mem->a;
		min = 999;
		while (l)
		{
			if (l->index == 0 || l->index == mem->max - 1)
			{
				now = step_to_top(mem->a, l->index);
				if (ft_abs(now) < ft_abs(min))
					min = now;
			}
			l = l->next;
		}
		if (min == 0)
			push_b(mem);
		if (min < 0)
			rev_rotate_a(mem);
		if (min > 0)
			rotate_a(mem);
	}
}
