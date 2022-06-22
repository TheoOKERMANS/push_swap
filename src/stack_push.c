/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:53:29 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:48:09 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if (stack_src && *stack_src)
	{
		temp = *stack_dest;
		*stack_dest = *stack_src;
		*stack_src = (*stack_src)->next;
		(*stack_dest)->next = temp;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
