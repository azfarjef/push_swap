/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:59:29 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:03:50 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap_a(t_mem *mem)
{
	swap_top(&(mem->a));
	if (mem->print)
		ft_putstr("sa");
}

void	swap_b(t_mem *mem)
{
	swap_top(&(mem->b));
	if (mem->print)
		ft_putstr("sb");
}

void	swap_b_a(t_mem *mem)
{
	swap_top(&(mem->b));
	swap_top(&(mem->a));
	if (mem->print)
		ft_putstr("ss");
}

void	push_b(t_mem *mem)
{
	push_top_x_to_y(&(mem->a), &(mem->b));
	if (mem->print)
		ft_putstr("pb");
}

void	push_a(t_mem *mem)
{
	push_top_x_to_y(&(mem->b), &(mem->a));
	if (mem->print)
		ft_putstr("pa");
}