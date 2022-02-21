# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 18:04:16 by mahmad-j          #+#    #+#              #
#    Updated: 2022/02/21 21:10:10 by mahmad-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	*.c
OBJ		=	${SRC:c=o}
INCLUDE	=	./

NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3

all		:	$(NAME)

$(NAME)	:	
			$(CC) $(CFLAGS) -c $(SRC) -I$(INCLUDE)
			$(CC) $(CFLAGS) $(OBJ) -I$(INCLUDE) -o $(NAME)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re