/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verif_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:54:44 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/25 17:54:46 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_long(const char *str)
{
	int			negative;
	long long	res;

	negative = 1;
	res = 0;
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	if (*str == '-' )
	{
		negative = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			break ;
		res *= 10;
		res += negative * (*str - 48);
		str++;
	}
	return (res);
}
