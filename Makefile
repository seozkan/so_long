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
NAME_B = so_long_b
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

B_SRC = bonus/so_long_bonus.c		\
		bonus/utils_bonus.c			\
		bonus/check_bonus.c			\
		bonus/path_bonus.c			\
		bonus/window_bonus.c		\
		bonus/put_bonus.c			\
		bonus/put_two_bonus.c		\
		bonus/key_bonus.c

OBJ = ${SRC:.c=.o}
B_OBJ = ${B_SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG)
			$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG) -o $(NAME) 
			@echo "$(YELLOW)${NAME} ✔️$(END)"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

$(MLX):
	@make -s -C $(MLX_DIR)

bonus: $(NAME_B)

$(NAME_B): 	$(B_OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG)
			$(CC) $(FLAGS) $(B_OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLX_ARG) -o $(NAME_B) 
			@echo "$(YELLOW)${NAME_B} ✔️$(END)"
n:
	norminette src bonus includes

v:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} maps/1.ber

clean:
	${RM} ${OBJ}
	${RM} ${B_OBJ}
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(PRINTF_DIR) clean

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_B}
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(PRINTF_DIR) fclean

re: clean all

.PHONY: all clean fclean re bonus