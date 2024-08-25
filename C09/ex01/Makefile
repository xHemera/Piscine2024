# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tobesnar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 13:51:13 by tobesnar          #+#    #+#              #
#    Updated: 2024/08/25 13:52:09 by tobesnar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
HEADER_DIR = includes
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(SRC_DIR)/, $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_DIR)/ft.h
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@
	@echo "Compiled $<."

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

# Clean object files and the library
fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
