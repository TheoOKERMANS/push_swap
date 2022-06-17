/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:09:33 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/26 17:52:56 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_solved(t_stack *stack)
{
	int		smallest;
	t_stack	*temp;

	smallest = stack->value;
	temp = stack->next;
	while (temp)
	{
		if (smallest >= temp->value)
			return (0);
		smallest = temp->value;
		temp = temp->next;
	}
	return (1);
}

size_t	get_len_stack(t_stack *stack)
{
	size_t	res;
	t_stack	*temp;

	res = 0;
	temp = stack;
	while (temp != NULL)
	{
		res++;
		temp = temp->next;
	}
	return (res);
}

t_stack	*get_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	best_rotate(t_stack *stack, int order)
{
	int		len;
	int		i;
	t_stack	*temp;

	len = get_len_stack(stack);
	i = 0;
	temp = stack;
	while (temp && order != temp->order)
	{
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
		return (-1);
	if (i <= len / 2)
		return (0);
	else
		return (1);
}

int	best_rotate_last(t_stack *stack, int order)
{
	int		len;
	int		i;
	t_stack	*temp;

	len = get_len_stack(stack);
	i = 0;
	temp = stack;
	while (temp && order != temp->order)
	{
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
		return (-1);
	if (i < len / 2)
		return (0);
	else
		return (1);
}
