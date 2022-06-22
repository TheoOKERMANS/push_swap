/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:52:37 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:13:12 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	highest_order(t_stack *stack)
{
	int		res;
	t_stack	*temp;

	res = 0;
	temp = stack;
	while (temp)
	{
		if (res < temp->order)
			res = temp->order;
		temp = temp->next;
	}
	return (res);
}

int	lowest_order(t_stack *stack)
{
	int		res;
	t_stack	*temp;

	res = 99;
	temp = stack;
	while (temp)
	{
		if (res > temp->order)
			res = temp->order;
		temp = temp->next;
	}
	return (res);
}

int	index_last(t_stack *stack, int min, int max)
{
	t_stack	*temp;
	int		i;

	i = get_len_stack(stack) - 1;
	temp = get_stack_index(stack, i);
	while (temp)
	{
		if (temp->order > min && temp->order < max)
			return (i);
		i--;
		temp = get_stack_index(stack, i);
	}
	return (-1);
}

int	index_first(t_stack *stack, int min, int max)
{
	t_stack	*temp;
	int		res;

	temp = stack;
	res = 0;
	while (temp)
	{
		if (temp->order > min && temp->order < max)
			return (res);
		temp = temp->next;
		res++;
	}
	return (-1);
}
