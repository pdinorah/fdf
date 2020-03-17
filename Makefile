# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdinorah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 15:29:36 by pdinorah          #+#    #+#              #
#    Updated: 2020/02/27 13:16:22 by pdinorah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c draw_the_line.c parser.c draw.c projection.c preparings.c

OBJ = main.o draw_the_line.o parser.o draw.o projection.o preparings.o

LIB_FLAG = -Llibft/ -lft

MINILIBX_FLAG = -L minilibx/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c fdf.h
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(CFLAGS) $(LIB_FLAG) $(OBJ) $(MINILIBX_FLAG)

clean:
	@/bin/rm -f *~
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean


re: fclean all
.PHONY: clean fclean all re
