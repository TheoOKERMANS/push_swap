/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:55:06 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:12:54 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	solve_manager_small(t_stack **stack)
{
	size_t	len;

	len = get_len_stack(*stack);
	if (len == 2)
		return (solve_2(stack));
	else if (len == 3)
		return (solve_3(stack));
	else
		return (solve_5(stack));
}

int	solve_manager_big(t_stack **stack)
{
	int	func_size_b;
	int	len;

	len = get_len_stack(*stack);
	if (len < 20)
		func_size_b = 5;
	else if (len <= 100)
		func_size_b = 28;
	else
		func_size_b = 60;
	solve_big(stack, func_size_b);
	return (1);
}

int	solve_manager(t_stack **stack)
{
	size_t	len;

	len = get_len_stack(*stack);
	if (len <= 5)
		return (solve_manager_small(stack));
	else
		return (solve_manager_big(stack));
}
