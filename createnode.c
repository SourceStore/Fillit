/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:49:24 by rishchen          #+#    #+#             */
/*   Updated: 2017/01/12 18:19:09 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		create_list(t_list *head, char *buf)
{
	t_list	*node;
	t_list	*fnode;
	int		i;

	i = 1;
	fnode = head;
	node = (t_list *)malloc(sizeof(t_list));
	ft_strcpy(node->content, buf);
	fi_co(node, -1);
	rel_coor(node);
	node->next = NULL;
	while (fnode->next)
	{
		fnode = fnode->next;
		i++;
	}
	fnode->next = node;
	node->word = 'A' + i;
}

t_list		*create_head(char *buf)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	ft_strcpy(head->content, buf);
	fi_co(head, -1);
	rel_coor(head);
	head->next = NULL;
	return (head);
}
