/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:01:40 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/21 16:12:22 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	main(int ac, char **av)
{
	t_mem	mem;
	t_list	*tagged;

	mem.a = NULL;
	mem.b = NULL;
	mem.print = 1;
	if (ac < 2)
		return (0);
	parse_arg(ac, av, &mem);
	if (!is_ordered(&mem))
	{
		tagged = (mem.a);
		sort_list(&tagged);
		tag_list(tagged, &mem);
		if (mem.max == 5)
			prep_five(&mem);
		solve(&mem, 1);
	}
	clear_mem(&mem);
	tagged = NULL;
	return (0);
}