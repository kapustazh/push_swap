YELLOW	= \033[33m
GREEN	= \033[32m
WHITE	= \033[37m
RESET	= \033[0m

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

NAME	= push_swap
CHECKER	= checker

SRC_DIR		= src
INC_DIR		= includes
LIBFT_DIR	= libft
GNL_DIR = get_next_line

SRCS_COMMON = \
    $(SRC_DIR)/parsing/parse.c \
    $(SRC_DIR)/stack/stack.c \
    $(SRC_DIR)/stack/stack_utils.c \
    $(SRC_DIR)/utils/utils.c \
    $(SRC_DIR)/utils/operations_utils.c \
    $(SRC_DIR)/sorting/sort.c \
    $(SRC_DIR)/sorting/sort_tiny.c \
    $(SRC_DIR)/sorting/sort_chunk.c \
    $(SRC_DIR)/operations/operations_swap.c \
    $(SRC_DIR)/operations/operations_push.c \
    $(SRC_DIR)/operations/operations_rotate.c \
    $(SRC_DIR)/operations/operations_rev_rotate.c

SRCS_PUSH_SWAP = $(SRC_DIR)/main/push_swap.c

SRCS_CHECKER = $(SRC_DIR)/checker/checker.c \
               $(SRC_DIR)/checker/checker_utils.c

GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRCS	= $(SRCS_PUSH_SWAP) $(SRCS_COMMON)
SRCS_BONUS = $(SRCS_CHECKER) $(SRCS_COMMON) $(GNL_SRCS)

OBJS	= $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT	= $(LIBFT_DIR)/libft.a

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Making $(NAME)$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)clean$(RESET)"

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)fclean$(RESET)"

bonus: $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(CHECKER)
	@echo "$(GREEN)Making $(CHECKER)$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus