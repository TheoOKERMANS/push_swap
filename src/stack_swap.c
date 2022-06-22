/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:13:43 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:48:23 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}

void	swap_a(t_stack **stack)
{
	swap(stack);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack)
{
	swap(stack);
	ft_putstr("sb\n");
}

void	swap_two(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_putstr("ss\n");
}
