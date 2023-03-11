# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 14:49:07 by seozkan           #+#    #+#              #
#    Updated: 2023/02/25 14:15:34 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
RM = @rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror

YELLOW = \033[33;49;1m
END = \033[0;0m

SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c
	
BNS_SRC = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c
	
OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $?
	@echo "$(YELLOW)${NAME} ✔️$(END)"

bonus: $(OBJ) $(BNS_OBJ)
	$(AR) $(NAME) $?
	@echo "$(YELLOW)${NAME} bonus ✔️$(END)"
	
%.o: %.c
	$(CC) -c $(FLAGS) $?
	
clean:
	$(RM) $(OBJ) $(BNS_OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re