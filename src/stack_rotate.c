/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:53:10 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:48:19 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	(temp->next)->next = NULL;
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	ft_putstr("rb\n");
}

void	rotate_two(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
