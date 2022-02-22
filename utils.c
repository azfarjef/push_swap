/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:41:57 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 17:14:52 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	ft_isdigit(int a)
{
	return (a >= '0' && a <= '9');
}

int	ft_isn(int a)
{
	return (a != '+' && a != '-' && a != ' ' && !ft_isdigit(a));
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
