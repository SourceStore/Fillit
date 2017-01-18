/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:41:05 by opodolia          #+#    #+#             */
/*   Updated: 2017/01/16 15:41:07 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct		s_fillit
{
	int				x[4];
	int				y[4];
	int				coor[4][2];
	char			word;
	char			content[22];
	struct s_fillit	*next;
}					t_list;

void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
int					checker_f(char *buf, int i);
int					checker_l(char *buf, int i);
int					validator(char *str);
void				fi_co(t_list *node, int i);
void				rel_coor(t_list *node);
int					min_size_matr(t_list *head);
t_list				*create_head(char *buf);
void				create_list(t_list *head, char *buf);
void				free_matr(char **matr, int min_size);
void				delete_tetr(char **matr, t_list *prev_node);
void				put_fig(char **matr, t_list *node, int i, int j);
int					try(char **matr, t_list *node, int i, int j);
char				**ren_map(int size);
int					brutforce(char **matr, t_list *node);
char				**rec_main(t_list *head);
int					start_point(char **argv);
void				print_res(char **res);

#endif
