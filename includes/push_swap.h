/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:11:22 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:14:27 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				order;
	struct s_stack	*next;
}	t_stack;

//init_cut_string
void		free_all(char ***tabl);
char		**cut_string(char *s);

//init_verif_arg
int			verif_arg_all_int(char **args);
int			verif_arg_twice_num(char **args);
int			verif_arg_size(char **args);
int			verif_arg(char **args);

//init
void		init_oder(t_stack *stack);
t_stack		*new_stack(int value);
void		add_back(t_stack **stack, t_stack *new);
void		free_stack(t_stack *stack);
t_stack		*init_a_stack(char **args);

//main
int			main(int argc, char **argv);

//solve_big
t_stack		*get_stack_index(t_stack *stack, int index);
void		push_into_b(t_stack **stack_a, t_stack **stack_b, int min, int max);
void		prepare_b(t_stack **sa, t_stack **stack_b, int b, int s);
void		solve_big(t_stack **sa, int s);

//solve_manager
int			solve_manager_small(t_stack **stack);
int			solve_manager_big(t_stack **stack);
int			solve_manager(t_stack **stack);

//solve_small
int			solve_2(t_stack **stack);
int			solve_3(t_stack **stack);
void		continue_rotate_a(t_stack **sa, t_stack **sb);
int			solve_5(t_stack **stack_a);

//stack_push
void		push(t_stack **stack_src, t_stack **stack_dest);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_b, t_stack **stack_a);

//stack_reverse_rotate
void		reverse_rotate(t_stack **stack);
void		reverse_rotate_a(t_stack **stack);
void		reverse_rotate_b(t_stack **stack);
void		reverse_rotate_two(t_stack **stack_a, t_stack **stack_b);

//stack_rotate
void		rotate(t_stack **stack);
void		rotate_a(t_stack **stack);
void		rotate_b(t_stack **stack);
void		rotate_two(t_stack **stack_a, t_stack **stack_b);

//stack_swap
void		swap(t_stack **stack);
void		swap_a(t_stack **stack);
void		swap_b(t_stack **stack);
void		swap_two(t_stack **a_stack, t_stack **b_stack);

//utils_init
int			is_with_space(char c);

//utils_print
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putchar_error(char c);
void		ft_putstr_error(char *s);
void		print_stack(t_stack *stack);

//utils_solver
int			stack_is_solved(t_stack *stack);
size_t		get_len_stack(t_stack *stack);
t_stack		*get_last(t_stack *stack);
int			best_rotate(t_stack *stack, int order);
int			best_rotate_last(t_stack *stack, int order);

//utils_solver2
void		rotate_with_letter(t_stack **stack, int a);
void		reverse_rotate_with_letter(t_stack **stack, int a);
int			put_highest_below_order(t_stack **stack, int order, int a);
int			get_last_order(t_stack *stack);

//utils_solver3
int			highest_order(t_stack *stack);
int			lowest_order(t_stack *stack);
int			index_last(t_stack *stack, int min, int max);
int			index_first(t_stack *stack, int min, int max);

//utils_verif_arg
long long	ft_atoi_long(const char *str);

#endif