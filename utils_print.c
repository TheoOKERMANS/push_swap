/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:09:24 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/26 15:20:03 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void	ft_putstr_error(char *s)
{
	while (*s)
	{
		ft_putchar_error(*s);
		s++;
	}
}

void	print_stack(t_stack *stack)
{
	char	*i;

	while (stack)
	{
		i = ft_itoa(stack->order);
		ft_putstr(i);
		free(i);
		ft_putstr("|");
		i = ft_itoa(stack->value);
		ft_putstr(i);
		free(i);
		ft_putstr("\n");
		stack = stack->next;
	}
}
