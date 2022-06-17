/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:12:20 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/30 13:01:06 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**spl;
	t_stack	*stack;

	if (argc <= 1 || ft_strlen(argv[1]) == 0)
		return (1);
	if (argc == 2)
		spl = cut_string(argv[1]);
	else if (argc > 2)
		spl = &(argv[1]);
	if (argc > 1 && verif_arg(spl))
	{
		stack = init_a_stack(spl);
		solve_manager(&stack);
		free_stack(stack);
	}
	if (argc == 2)
	{
		i = 0;
		while (spl[i])
			free(spl[i++]);
		free(spl);
	}	
	return (1);
}
