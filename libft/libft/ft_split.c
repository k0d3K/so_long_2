/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:46:18 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 21:05:25 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	count;
	int	nb_words;

	count = 0;
	nb_words = 0;
	while (str[count] && str[count] == c)
		count++;
	while (str[count])
	{
		nb_words++;
		count++;
		while (str[count] && str[count] != c)
			count++;
		while (str[count] && str[count] == c)
			count++;
	}
	return (nb_words);
}

static char	**creat_tab(char **tab, int size_tab, char *str, char c)
{
	int		size;
	int		count;

	count = 0;
	while (count < size_tab)
	{
		size = 0;
		while (*str && *str == c)
			str++;
		while (str[size] && str[size] != c)
			size++;
		tab[count] = (char *)malloc(sizeof(char) * (size + 1));
		if (!tab[count])
		{
			while (count > 0)
				free(tab[count--]);
			free (tab);
			return (0);
		}
		str += size + 1;
		count++;
	}
	return (tab);
}

static void	str_to_tab(char **tab, int size_tab, char *str, char c)
{
	int	count;
	int	count2;
	int	size;

	count = 0;
	while (count < size_tab)
	{
		count2 = 0;
		size = 0;
		while (*str && *str == c)
			str++;
		while (str[size] && str[size] != c)
			size++;
		while (count2 < size)
		{
			tab[count][count2] = str[count2];
			count2++;
		}
		str += size + 1;
		tab[count++][count2] = 0;
	}
	tab[count] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		size_tab;

	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	size_tab = count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * (size_tab + 1));
	if (!tab)
		return (0);
	tab = creat_tab(tab, size_tab, str, c);
	if (!tab)
		return (0);
	str_to_tab(tab, size_tab, str, c);
	free(str);
	return (tab);
}
