# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 22:00:00 by mnestere          #+#    #+#              #
#    Updated: 2025/11/26 22:26:59 by mnestere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW	= \033[33m
GREEN	= \033[32m
WHITE	= \033[37m
RESET	= \033[0m

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

NAME	= push_swap

SRC_DIR		= src
INC_DIR		= includes
LIBFT_DIR	= libft

SRCS	= $(SRC_DIR)/push_swap.c \
		  $(SRC_DIR)/parse.c \
		  $(SRC_DIR)/stack.c \
		  $(SRC_DIR)/stack_utils.c \
		  $(SRC_DIR)/utils.c \
		  $(SRC_DIR)/sort.c \
		  $(SRC_DIR)/operations_swap.c \
		  $(SRC_DIR)/operations_push.c \
		  $(SRC_DIR)/operations_rotate.c \
		  $(SRC_DIR)/operations_rev_rotate.c \
		  $(SRC_DIR)/sort_three.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= $(LIBFT_DIR)/libft.a

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) Making$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN) clean$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN) fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re
