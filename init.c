/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:54:00 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/25 17:54:01 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_oder(t_stack *stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		len;
	int		nb_smaller;

	len = get_len_stack(stack);
	temp1 = stack;
	while (temp1 != NULL)
	{
		temp2 = stack;
		nb_smaller = 0;
		while (temp2 != NULL)
		{
			if (temp1->value < temp2->value)
				nb_smaller++;
			temp2 = temp2->next;
		}
		temp1->order = len - nb_smaller;
		temp1 = temp1->next;
	}
}

t_stack	*new_stack(int value)
{
	t_stack	*res;

	res = ft_calloc(1, sizeof(t_stack));
	if (res == NULL)
		return (NULL);
	res->next = NULL;
	res->order = 0;
	res->value = value;
	return (res);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (stack)
	{
		if (*stack)
		{
			temp = *stack;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
		else
		{
			*stack = new;
		}
	}
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->next != NULL)
			free_stack(stack->next);
		free(stack);
	}
}

t_stack	*init_a_stack(char **args)
{
	t_stack	*res;
	t_stack	*temp;

	res = NULL;
	while (*args != NULL)
	{
		temp = new_stack(ft_atoi(*args));
		if (temp == NULL)
		{
			free_stack(res);
			return (NULL);
		}
		add_back(&res, temp);
		args++;
	}
	init_oder(res);
	return (res);
}
