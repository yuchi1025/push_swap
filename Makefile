# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 15:17:57 by yucchen           #+#    #+#              #
#    Updated: 2025/09/28 14:13:49 by yucchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and parameters
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make

# File name and file list
NAME = push_swap
SOURCES = split_argv_utils.c \
		  split_argv.c \
		  number_check.c \
		  main.c
OBJECTS = $(SOURCES:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT_AR = $(LIBFT_DIR)/libft.a

# Tools
RM = rm -f

# Rules
# Compile mandatory part
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_AR) -o $(NAME)

$(LIBFT_AR):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean: 
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJECTS)

# Clean object files and lib
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re