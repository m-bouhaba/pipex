# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 21:05:06 by mbouhaba          #+#    #+#              #
#    Updated: 2022/02/19 21:10:33 by mbouhaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc 
SFLAGS = -Wall -Wextra -Werror
SRC = pipex.c free.c child.c pipex_utils.c  ft_split.c 
OBJ = ${SRC:.c=.o} 

all : $(NAME)
	 
$(NAME): $(OBJ)
		$(CC) $(SFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ) 
fclean : clean
	 rm -rf $(NAME)
re : fclean all
