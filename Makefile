# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 21:05:06 by mbouhaba          #+#    #+#              #
#    Updated: 2022/02/16 22:47:45 by mbouhaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc 
FLAGS = -Wall -Wextra -Werror
SRC = pipex.c free.c child.c pipex_utils.c  ft_split.c 
OBJ = ${SRC:.c=.o} 

all : $(NAME)
	 
$(NAME): $(OBJ)
		$(CC) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ) 
fclean : clean
	 rm -rf $(NAME)
re : fclean all
