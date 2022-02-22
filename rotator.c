/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:35:33 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:30:17 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	double_rotate(t_mem *mem, int *rota, int *rotb)
{
	while (*rota > 0 && *rotb > 0)
	{
		(*rota)--;
		(*rotb)--;
		rotate_b_a(mem);
	}
	while (*rota < 0 && *rotb < 0)
	{
		(*rota)++;
		(*rotb)++;
		rev_rotate_b_a(mem);
	}
}

void	rotate(t_mem *mem, int rota, int rotb)
{
	double_rotate(mem, &rota, &rotb);
	while (rota > 0)
	{
		rota--;
		rotate_a(mem);
	}
	while (rota < 0)
	{
		rota++;
		rev_rotate_a(mem);
	}
	while (rotb > 0)
	{
		rotb--;
		rotate_b(mem);
	}
	while (rotb < 0)
	{
		rotb++;
		rev_rotate_b(mem);
	}
}
