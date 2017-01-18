/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrandtetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:07:01 by rishchen          #+#    #+#             */
/*   Updated: 2017/01/12 18:20:34 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_matr(char **matr, int min_size)
{
	int		i;

	i = -1;
	while (++i < min_size)
		free(matr[i]);
	free(matr);
}

void		delete_tetr(char **matr, t_list *prev_node)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (matr[++i])
	{
		while (matr[++j])
		{
			if (prev_node != NULL && matr[i][j] == prev_node->word)
				matr[i][j] = '.';
		}
		j = -1;
	}
}

void		put_fig(char **matr, t_list *node, int i, int j)
{
	int		s;

	s = -1;
	while (++s < 4)
		matr[i - node->y[s]][j + node->x[s]] = node->word;
}

int			try(char **matr, t_list *node, int i, int j)
{
	int		s;
	int		len;

	s = -1;
	len = ft_strlen(matr[0]);
	while (++s < 4)
	{
		if (len > i - node->y[s] && len > j + node->x[s])
			if (matr[i - node->y[s]][j + node->x[s]] != '.')
				return (0);
		if (len <= i - node->y[s] || len <= j + node->x[s])
			return (0);
	}
	return (1);
}

char		**ren_map(int size)
{
	char	**matr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	matr = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		matr[i] = (char *)malloc(sizeof(char) * size + 1);
		while (j < size)
		{
			matr[i][j] = '.';
			j++;
		}
		matr[i][j] = '\0';
		j = 0;
		i++;
	}
	matr[size] = 0;
	return (matr);
}
