/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:13:34 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:48:14 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (stack && *stack)
	{
		temp = *stack;
		while ((temp->next)->next != NULL)
			temp = temp->next;
		(temp->next)->next = *stack;
		*stack = temp->next;
		temp->next = NULL;
	}
}

void	reverse_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putstr("rrb\n");
}

void	reverse_rotate_two(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
