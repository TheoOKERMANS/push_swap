/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:14:55 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/30 14:54:26 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_stack_index(t_stack *stack, int index)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	i = 0;
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

void	push_into_b(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int		f_ind;
	int		l_ind;
	size_t	len;

	len = get_len_stack(*stack_a);
	f_ind = index_first(*stack_a, min, max);
	l_ind = index_last(*stack_a, min, max);
	if ((int)len - l_ind > f_ind)
		while (index_first(*stack_a, min, max) != 0)
			rotate_a(stack_a);
	else
		while (index_first(*stack_a, min, max) != 0)
			reverse_rotate_a(stack_a);
	if (get_len_stack(*stack_b) > 1)
		put_highest_below_order(stack_b, (*stack_a)->order, 0);
	push_b(stack_b, stack_a);
}

void	prepare_b(t_stack **sa, t_stack **stack_b, int b, int s)
{
	if (index_first(*sa, (*stack_b)->order + 1, (*stack_b)->order + 3) != -1)
	{
		if (b != 1)
		{
			put_highest_below_order(sa, ((b - 1) * s) + 1, 1);
			rotate_a(sa);
		}
	}
	else
		put_highest_below_order(sa, 2, 1);
}

void	solve_big(t_stack **sa, int s)
{
	int		b;
	t_stack	*stack_b;

	b = 1;
	stack_b = NULL;
	while ((b - 1) * s < (int)get_len_stack(*sa) && stack_is_solved(*sa) == 0)
	{
		while (index_first(*sa, (b - 1) * s, (b * s) + 1) != -1)
			push_into_b(sa, &stack_b, (b - 1) * s, (b * s) + 1);
		put_highest_below_order(&stack_b, highest_order(stack_b) + 1, 0);
		if (get_len_stack(stack_b) > 0)
			prepare_b(sa, &stack_b, b, s);
		while (get_len_stack(stack_b) > 0)
			push_a(sa, &stack_b);
		b++;
	}
	put_highest_below_order(sa, 2, 1);
}
