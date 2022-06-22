/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_verif_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:12:06 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 14:12:46 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	verif_arg_all_int(char **args)
{
	size_t	arg_i;
	size_t	word_i;

	arg_i = 0;
	while (args[arg_i])
	{
		word_i = 0;
		if (args[arg_i][word_i] == '-' && args[arg_i][word_i + 1] == '\0')
			return (0);
		if (args[arg_i][word_i] == '-')
			word_i++;
		while (args[arg_i][word_i])
		{
			if (args[arg_i][word_i] < '0' || args[arg_i][word_i] > '9')
				return (0);
			word_i++;
		}
		arg_i++;
	}
	return (1);
}

int	verif_arg_twice_num(char **args)
{
	int	len;
	int	len_arg;
	int	fir;
	int	sec;

	len = 0;
	while (args[len] != NULL)
		len++;
	fir = 0;
	while (fir < len - 1)
	{
		sec = fir + 1;
		while (sec < len)
		{
			len_arg = ft_strlen(args[fir]);
			if ((int)ft_strlen(args[sec]) > len_arg)
				len_arg = ft_strlen(args[sec]);
			if (ft_strncmp(args[fir], args[sec], len_arg) == 0)
				return (0);
			sec++;
		}
		fir++;
	}
	return (1);
}

int	verif_arg_size(char **args)
{
	int			i;
	long long	value;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			return (0);
		value = ft_atoi_long(args[i]);
		if (value < -2147483648 || value > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	verif_arg(char **args)
{
	if (args == NULL || *args == NULL)
	{
		ft_putstr_error("Error\n");
		return (0);
	}
	if (verif_arg_all_int(args) == 0)
	{
		ft_putstr_error("Error\n");
		return (0);
	}
	if (verif_arg_twice_num(args) == 0)
	{
		ft_putstr_error("Error\n");
		return (0);
	}
	if (verif_arg_size(args) == 0)
	{
		ft_putstr_error("Error\n");
		return (0);
	}
	return (1);
}
