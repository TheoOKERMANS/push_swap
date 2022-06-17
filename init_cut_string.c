/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cut_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:55:52 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/25 18:48:05 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nb_word(char const *s)
{
	int	res;
	int	word;

	res = 0;
	word = 0;
	while (*s)
	{
		if (is_with_space(*s) && word)
		{
			res++;
			word = 0;
		}
		else if (is_with_space(*s) == 0 && word == 0)
			word = 1;
		s++;
	}
	if (word == 1)
		res++;
	return (res);
}

static int	get_len_word(char const *s, int index)
{
	int	res;
	int	word;

	res = 0;
	word = 0;
	while (index)
	{
		if (is_with_space(*s) && word)
		{
			index--;
			word = 0;
		}
		else if (is_with_space(*s) == 0 && word == 0)
			word = 1;
		s++;
	}
	while (is_with_space(*s))
		s++;
	while (*s != '\0' && is_with_space(*s++) == 0)
		res++;
	return (res);
}

static const char	*get_pointer_word(char const *s, int index)
{
	int	word;

	word = 0;
	while (index)
	{
		if (is_with_space(*s) && word)
		{
			index--;
			word = 0;
		}
		else if (is_with_space(*s) == 0 && word == 0)
			word = 1;
		s++;
	}
	while (is_with_space(*s))
		s++;
	return (s);
}

void	free_all(char ***tabl)
{
	int	i;

	i = 0;
	while (*tabl[i] != NULL)
	{
		free(*tabl[i]);
		i++;
	}
	free(*tabl);
}

char	**cut_string(char *s)
{
	char		**res;
	int			nb_word;
	int			len_word;
	const char	*p_word;

	nb_word = get_nb_word(s);
	res = ft_calloc(nb_word + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (nb_word > 0)
	{
		len_word = get_len_word(s, nb_word - 1) + 1;
		res[nb_word - 1] = ft_calloc(len_word, sizeof(char));
		if (res[nb_word - 1] == NULL)
		{
			free_all(&res);
			return (NULL);
		}
		p_word = get_pointer_word(s, nb_word - 1);
		ft_strlcpy(res[nb_word - 1], p_word, len_word);
		nb_word--;
	}
	return (res);
}
