/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfigure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:50:16 by rishchen          #+#    #+#             */
/*   Updated: 2017/01/13 21:26:01 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count(int i, char *buf)
{
	int k;

	k = 0;
	if (buf[i + 1] == '#')
		k++;
	if (buf[i - 1] == '#')
		k++;
	if (buf[i + 5] == '#')
		k++;
	if (buf[i - 5] == '#')
		k++;
	return (k);
}

int		ft_valid(char *buf)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' ||
			buf[19] != '\n' || (buf[20] != '\0' && buf[20] != '\n'))
		return (1);
	while (i < 20)
	{
		if (i != 4 && i != 9 && i != 14 && i != 19 && (buf[i] != '.'
					&& buf[i] != '#'))
			return (1);
		if (buf[i] == '#')
		{
			j++;
			k += ft_count(i, buf);
		}
		i++;
	}
	if (j != 4 || (k != 6 && k != 8))
		return (1);
	return (0);
}

int		validator(char *str)
{
	int		flag;
	int		fd;
	int		ret;
	int		count;
	char	buf[22];

	count = 0;
	buf[21] = 0;
	fd = open(str, O_RDONLY);
	while ((ret = read(fd, buf, 21)))
	{
		flag = 1;
		if (ret == 20)
			flag = 0;
		buf[ret] = '\0';
		if (ft_valid(buf))
			return (0);
		count++;
	}
	if (count > 26 || flag)
		return (0);
	close(fd);
	return (1);
}
