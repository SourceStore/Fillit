/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcoor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:12:55 by rishchen          #+#    #+#             */
/*   Updated: 2017/01/12 20:27:16 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		rel_coor(t_list *node)
{
	int		x;
	int		y;
	int		j;

	j = -1;
	x = node->coor[0][0];
	y = node->coor[0][1];
	while (++j < 4)
	{
		node->x[j] = node->coor[j][0] - x;
		node->y[j] = y - node->coor[j][1];
	}
}

void		fi_co(t_list *node, int i)
{
	int		x1;
	int		y1;
	int		k;

	x1 = 0;
	y1 = 0;
	k = 0;
	while (node->content[++i])
	{
		if (node->content[i] == '#')
		{
			node->coor[k][0] = x1;
			node->coor[k][1] = y1;
			x1++;
			k++;
		}
		if (node->content[i] == '\n')
		{
			x1 = 0;
			y1++;
		}
		if (node->content[i] == '.')
			x1++;
	}
}

int			min_size_matr(t_list *head)
{
	t_list	*f_el;
	int		i;
	int		j;

	i = 0;
	j = 0;
	f_el = head;
	while (f_el->next)
	{
		f_el = f_el->next;
		i++;
	}
	i++;
	while ((j * j) < 4 * i)
		j++;
	return (j);
}
