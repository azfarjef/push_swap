/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:04:10 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/02/22 18:16:42 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long			value;
	int				index;
	int				keep;
	struct s_list	*next;
	struct s_list	*next_sort;
}					t_list;

typedef struct s_mem
{
	t_list			*a;
	t_list			*b;
	int				max;
	int				big;
	int				size;
	int				groupnum;
	int				groupsize;
	int				print;
	t_list			*tmp;
}					t_mem;

/*
	Utils
*/
int		ft_isdigit(int c);
int		ft_isn(int a);
int		ft_atoi(char *str, t_mem *mem);
int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_putstr(char *str);
/*
	List_ft
*/
int		value_in_list(t_list *lst, int value);
void	fill_list(t_list **lst, int value, int tag, t_mem *mem);
int		is_ordered(t_mem *mem);
void	swap_list(t_list **keep, t_list *two);
void	sort_list(t_list **tagged);
void	tag_list(t_list *list, t_mem *mem);
t_list	*get_last(t_list *l);
/*
	Prepare
*/
void	parse_arg(int ac, char **av, t_mem *mem, int f);
void	prep_five(t_mem *mem);
int		has_tag(t_list *list, int tag);
int		list_size(t_list *l);
int		step_to_top(t_list *l, int tag);
/*
	Solver
*/
void	solve(t_mem *m, int group);
void	init_solve(t_mem *mem);
int		biggest_loop(t_list *start, int set);
int		loop_list(t_list *list, t_list *start, int set);
t_list	*closest_in_group(t_list *l, int group, int groupsize);
int		can_swap(t_list *l);
void	rotate(t_mem *mem, int rota, int rotb);
void	double_rotate(t_mem *mem, int *rota, int *rotb);
void	fill_b(t_mem *m);
void	b_rotation(t_mem *m, int max_step, int *rota, int *rotb);
int		step_to_tag(int tag, int size);
/*
	Actions
*/
void	swap_a(t_mem *mem);
void	swap_b(t_mem *mem);
void	swap_b_a(t_mem *mem);
void	push_a(t_mem *mem);
void	push_b(t_mem *mem);
void	rotate_a(t_mem *mem);
void	rotate_b(t_mem *mem);
void	rotate_b_a(t_mem *mem);
void	rev_rotate_a(t_mem *mem);
void	rev_rotate_b(t_mem *mem);
void	rev_rotate_b_a(t_mem *mem);
void	swap_top(t_list **mem);
void	push_top_x_to_y(t_list **x, t_list **y);
void	last_to_first(t_list **x);
void	first_to_last(t_list **x);
/*
	Clear
*/
void	exit_error(t_mem *mem);
void	print_error(char *str);
void	clear_mem(t_mem *mem);
void	ft_freelst(t_list **list);

#endif