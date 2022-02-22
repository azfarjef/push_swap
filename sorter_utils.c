/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:43:48 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:28:07 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_solve(t_mem *mem)
{
	mem->big = biggest_loop(mem->a, 1);
	mem->size = list_size(mem->a);
	mem->groupnum = ft_max(1, (int)(mem->max / 150.0));
	mem->groupsize = mem->max / mem->groupnum;
}

int	step_to_top(t_list *l, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(l);
	while (l)
	{
		if (l->index == tag)
			break ;
		l = l->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

int	step_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

t_list	*closest_in_group(t_list *l, int group, int groupsize)
{
	t_list	*closest;
	t_list	*now;
	int		step;
	int		now_step;

	step = 0xFFFFFFF;
	closest = NULL;
	now = l;
	while (now)
	{
		if (now->index <= groupsize * group && !now->keep)
		{
			now_step = step_to_top(l, now->index);
			if (ft_abs(now_step) < ft_abs(step))
			{
				step = now_step;
				closest = now;
				if (step == 0)
					break ;
			}
		}
		now = now->next;
	}
	return (closest);
}
