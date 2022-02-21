/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:13:10 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/21 22:32:04 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	can_swap(t_list *l)
{
	t_list	a;
	t_list	b;
	int		ori;
	int		swap;
	
	a.next = &b;
	a.index = l->next->index;
	b.next = l->next->next;
	b.index = l->index;
	ori = biggest_loop(l, 0);
	swap = biggest_loop(&a, 0);
	if (swap > ori)
		return (1);
	return (0);
}

void	solve(t_mem *m, int group)
{
	int step;

	init_solve(m);
	while (m->size >= m->big && group <= (m->groupnum + 1))
	{
		m->tmp = closest_in_group(m->a, group, m->groupsize);
		if (m->tmp == NULL && ++group)
			continue ;
		step = step_to_top(m->a, m->tmp->index);
		if (m->a && can_swap(m->a))
		{
			swap_a(m);
			m->big = biggest_loop(m->a, 1);
		}
		else if (m->a && !m->a->keep && step == 0)
		{
			push_b(m);
			(m->size)--;
		}
		else if (m->groupnum == 1 && m->b && m->b->next)
			rotate_b_a(m);
		else
			rotate(m, ft_min(1, ft_max(-1, step)), 0);
	}
}