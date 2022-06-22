/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:08:52 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:12:56 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	solve_2(t_stack **stack)
{
	if (stack_is_solved(*stack) == 0)
		swap_a(stack);
	return (1);
}

int	solve_3(t_stack **stack)
{
	int	n1;
	int	n2;
	int	n3;
	int	res;

	res = 0;
	while (stack_is_solved(*stack) == 0)
	{
		n1 = (*stack)->value;
		n2 = (*stack)->next->value;
		n3 = (*stack)->next->next->value;
		if (n1 > n2 && n2 < n3 && n1 > n3 && res++ > -1)
			rotate_a(stack);
		else if (n1 < n2 && n2 > n3 && n1 > n3)
		{
			reverse_rotate_a(stack);
			res++;
		}
		else
		{
			swap_a(stack);
			res++;
		}
	}
	return (res);
}

void	continue_rotate_a(t_stack **sa, t_stack **sb)
{
	int	up;
	int	best_ro;
	int	len;

	len = get_len_stack(*sa) + get_len_stack(*sb);
	up = (*sb)->order + 1;
	while (up <= len && index_first(*sa, up - 1, up + 1) == -1)
		up++;
	if (up > len)
		up = 1;
	while (up <= len && index_first(*sa, up - 1, up + 1) == -1)
		up++;
	best_ro = best_rotate(*sa, up);
	while (index_first(*sa, up - 1, up + 1) != 0)
	{
		if (best_ro == 0)
			rotate_a(sa);
		else
			reverse_rotate_a(sa);
	}
}

int	solve_5(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	len;
	int		res;

	stack_b = NULL;
	res = 0;
	len = get_len_stack(*stack_a);
	while (len-- > 3 && res++ > -1)
		push_b(&stack_b, stack_a);
	solve_3(stack_a);
	len = get_len_stack(stack_b);
	while (len-- > 0)
	{
		continue_rotate_a(stack_a, &stack_b);
		push_a(stack_a, &stack_b);
	}
	res += put_highest_below_order(stack_a, 2, 1);
	return (res);
}
