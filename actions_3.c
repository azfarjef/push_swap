/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:28:00 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/21 22:30:04 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate_b_a(t_mem *mem)
{
	first_to_last(&(mem->a));
	first_to_last(&(mem->b));
	if (mem->print)
		ft_putstr("rr");	
}