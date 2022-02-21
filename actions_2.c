/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:29:47 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/21 22:55:09 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rev_rotate_a(t_mem *mem)
{
	last_to_first(&(mem->a));
	if (mem->print)
		ft_putstr("rra");
}

void	rev_rotate_b(t_mem *mem)
{
	last_to_first(&(mem->b));
	if (mem->print)
		ft_putstr("rrb");
}

void	rev_rotate_b_a(t_mem *mem)
{
	last_to_first(&(mem->b));
	last_to_first(&(mem->a));
	if (mem->print)
		ft_putstr("rrr");
}

void	rotate_a(t_mem *mem)
{
	first_to_last(&(mem->a));
	if (mem->print)
		ft_putstr("ra");
}

void	rotate_b(t_mem *mem)
{
	first_to_last(&(mem->b));
	if (mem->print)
		ft_putstr("rb");
}