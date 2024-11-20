/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:35:02 by lguerbig          #+#    #+#             */
/*   Updated: 2024/11/20 02:06:32 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**tab_join_free(char **tab, char *line)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (size_tab(tab) + 2));
	if (!res)
	{
		free_tab((void **)tab);
		return (NULL);
	}
	while (tab && tab[i])
	{
		res[i] = tab[i];
		i++;
	}
	free(tab);
	res[i++] = line;
	res[i] = 0;
	return (res);
}

char	*str_cpy_nl(char *str)
{
	int		i;
	char	*str_cpy;

	i = 0;
	str_cpy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!str_cpy)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = 0;
	return (str_cpy);
}

char	**tab_cpy(char **tab)
{
	int		j;
	int		height;
	char	**tab_cpy;

	height = 0;
	while (tab[height])
		height++;
	tab_cpy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!tab_cpy)
		return (NULL);
	j = 0;
	while (tab[j])
	{
		tab_cpy[j] = str_cpy_nl(tab[j]);
		if (!tab_cpy[j])
		{
			free_tab((void **)tab_cpy);
			return (NULL);
		}
		j++;
	}
	tab_cpy[j] = 0;
	return (tab_cpy);
}
