# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 18:43:07 by rishchen          #+#    #+#              #
#    Updated: 2017/01/16 13:26:19 by opodolia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = checkfigure.c\
	  createnode.c\
	  fillit.c\
	  findcoor.c\
	  ft_putstr.c\
	  ft_strcpy.c\
	  ft_strlen.c\
	  matrandtetr.c

OBJ = $(SRC:.c=.o)

FLG = -Wall -Wextra -Werror

CC = gcc

INC = ./

all:	$(NAME)

%.o: %.c 
	$(CC) -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o fillit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
