/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:54:06 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/17 21:39:55 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ft_freelst(t_list **list)
{
	t_list	*l;
	t_list	*next;
	
	l = *list;
	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
	*list = NULL;
}

void	clear_mem(t_mem *mem)
{
	ft_freelst(&(mem->a));
	ft_freelst(&(mem->b));
}

void	print_error(char *str)
{
	int		i;
	char	n;

	i = 0;
	while (str[i])
		i++;
	n = '\n';
	write(2, str, i);
	write(2, &n, 1);
}

void	exit_error(t_mem *mem)
{
	print_error("Error");
	clear_mem(mem);
	exit(EXIT_FAILURE);
}