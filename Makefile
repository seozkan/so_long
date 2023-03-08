# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 19:32:08 by seozkan           #+#    #+#              #
#    Updated: 2023/02/24 19:32:08 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror -g3

YELLOW = \033[33;49;1m
END = \033[0;0m

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = ./lib/mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_ARG = -lm -lX11 -lXext


SRC = 	src/so_long.c				\
		src/utils.c					\
		src/check.c					\
		src/path.c					\
		src/window.c				\
		src/put.c					\
		src/key.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG) -o $(NAME) 
	@echo "$(YELLOW)${NAME} ✔️$(END)"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make bonus -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

$(MLX):
	@make -s -C $(MLX_DIR)

n:
	norminette *c

v:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} maps/1.ber

clean:
	${RM} ${OBJ}
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(PRINTF_DIR) clean

fclean: clean
	${RM} ${NAME}
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(PRINTF_DIR) fclean

re: clean all

.PHONY: all clean fclean re bonus