/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:17:08 by rishchen          #+#    #+#             */
/*   Updated: 2017/01/16 15:37:11 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			brutforce(char **matr, t_list *node)
{
	int		i;
	int		j;

	if (!node)
		return (1);
	i = 0;
	while (matr[i])
	{
		j = 0;
		while (matr[i][j])
		{
			if (try(matr, node, i, j))
			{
				put_fig(matr, node, i, j);
				if (node->next == NULL)
					return (1);
				if (brutforce(matr, node->next))
					return (1);
				delete_tetr(matr, node);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char		**rec_main(t_list *head)
{
	int		i;
	int		min_size;
	t_list	*copy;
	char	**matr;

	i = 0;
	copy = head;
	min_size = min_size_matr(head);
	matr = ren_map(min_size);
	while (!(brutforce(matr, copy)))
	{
		free_matr(matr, min_size);
		min_size++;
		matr = ren_map(min_size);
	}
	return (matr);
}

void		print_res(char **res)
{
	size_t	ml;

	ml = 0;
	while (ml < ft_strlen(res[0]))
	{
		ft_putstr(res[ml]);
		write(1, &"\n", 1);
		ml++;
	}
}

int			start_point(char **argv)
{
	int		fd;
	char	buf[21];
	int		ret;
	t_list	*head;
	char	**res;

	*(buf + 21) = '\0';
	if (validator(argv[1]) != 0)
	{
		fd = open(argv[1], O_RDONLY);
		read(fd, buf, 21);
		head = create_head(buf);
		head->word = 'A';
		while ((ret = (read(fd, buf, 21))))
			create_list(head, buf);
		res = rec_main(head);
		print_res(res);
	}
	else
		ft_putstr("error\n");
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[4097];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	read(fd, buf, 4096);
	if (ft_strlen(buf) >= 546 || ft_strlen(buf) <= 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	start_point(argv);
	return (0);
}
