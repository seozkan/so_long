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
FLAGS = -Wall -Wextra -Werror -g

YELLOW = \033[33;49;1m
END = \033[0;0m

LIBFT_DIR = ./lib/libft/
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = 	src/so_long.c				\
		src/error.c					\
		src/utils.c					\
		src/check.c					\
		src/path.c					

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(YELLOW)${NAME} ✔️$(END)"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make bonus -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

n:
	norminette

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