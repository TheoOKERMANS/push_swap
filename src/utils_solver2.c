/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:15:54 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:13:10 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_with_letter(t_stack **stack, int a)
{
	if (a == 1)
		rotate_a(stack);
	else
		rotate_b(stack);
}

void	reverse_rotate_with_letter(t_stack **stack, int a)
{
	if (a == 1)
		reverse_rotate_a(stack);
	else
		reverse_rotate_b(stack);
}

int	put_highest_below_order(t_stack **stack, int order, int a)
{
	int		ob;
	int		res;

	ob = order - 1;
	res = 0;
	if (get_len_stack(*stack) > 0)
	{
		while (ob > 0 && index_first(*stack, ob - 1, ob + 1) == -1)
			ob--;
		if (ob == 0)
			ob = highest_order(*stack);
		if (best_rotate(*stack, ob) == 0)
		{
			while (index_first(*stack, ob - 1, ob + 1) != 0 && res++ > -1)
				rotate_with_letter(stack, a);
		}
		else
		{
			while (index_first(*stack, ob - 1, ob + 1) != 0 && res++ > -1)
				reverse_rotate_with_letter(stack, a);
		}
	}
	return (res);
}

int	get_last_order(t_stack *stack)
{
	return ((get_stack_index(stack, get_len_stack(stack) - 1))->order);
}
