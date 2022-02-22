/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:50:14 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 14:30:01 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_atoi(char *str, t_mem *mem)
{
	int		flag;
	long	nbr;

	flag = 1;
	nbr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		++str;
	}
	--str;
	while (++str && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if ((flag == 1 && nbr > 0x7FFFFFFF) || (flag == -1 && nbr > 0x80000000))
			exit_error(mem);
	}
	return ((int)(nbr * flag));
}

int	list_size(t_list *l)
{
	int	i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

t_list	*get_last(t_list *l)
{
	if (l == NULL)
		return (NULL);
	while (l->next)
		l = l->next;
	return (l);
}
