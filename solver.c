/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:13:10 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:26:45 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	insert_step(t_list *l, int n, int size)
{
	t_list	*a;
	t_list	*b;
	int		b_max[2];
	int		i;

	i = 0;
	a = get_last(l);
	b = l;
	b_max[1] = 0xFFFFFFF;
	while (b)
	{
		if ((a->index > b->index && (n < b->index || n > a->index))
			|| (n > a->index && n < b->index))
		{
			b_max[0] = i;
			if (b_max[0] > size / 2)
				b_max[0] -= size;
			if (ft_abs(b_max[0]) < b_max[1])
				b_max[1] = b_max[0];
		}
		a = b;
		b = b->next;
		i++;
	}
	return (b_max[1]);
}

void	b_rotation(t_mem *m, int max_step, int *rota, int *rotb)
{
	int	total_step;
	int	insert;
	int	b_step;
	int	i;

	i = 0;
	m->tmp = m->b;
	while (m->tmp)
	{
		b_step = step_to_tag(i++, m->max - m->size);
		insert = insert_step(m->a, m->tmp->index, m->size);
		total_step = ft_abs(insert) + ft_abs(b_step);
		if (insert > 0 && b_step > 0)
			total_step -= ft_min(b_step, insert);
		if (insert < 0 && b_step < 0)
			total_step += ft_max(b_step, insert);
		if (total_step < max_step)
		{
			max_step = total_step;
			*rota = insert;
			*rotb = b_step;
		}
		m->tmp = m->tmp->next;
	}
}

void	fill_b(t_mem *m)
{
	int	rota;
	int	rotb;

	while (m->b)
	{
		b_rotation(m, 0xFFFFFFF, &rota, &rotb);
		rotate(m, rota, rotb);
		push_a(m);
		(m->size)++;
	}
	rotate(m, step_to_top(m->a, 0), 0);
}

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
	int	step;

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
	fill_b(m);
}
