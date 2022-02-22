/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:15:35 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 18:26:49 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	parse_arg(int ac, char **av, t_mem *mem, int f)
{
	int	i;
	int	j;
	int	flag_space;

	i = 1;
	while (i < ac)
	{
		flag_space = 1;
		f = 0;
		j = -1;
		while (av[i][++j])
		{
			if (ft_isn(av[i][j]) || (!ft_isdigit(av[i][j]) && av[i][j] != ' '
				&& f == 1 && flag_space != 1))
				exit_error(mem);
			if (av[i][j] != ' ' && flag_space == 1)
			{
				fill_list(&(mem->a), ft_atoi(av[i] + j, mem), -1, mem);
				flag_space = 0;
				f = 1;
			}
			flag_space = av[i][j] == ' ';
		}
		i++;
	}
}
