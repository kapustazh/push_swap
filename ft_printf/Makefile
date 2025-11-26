CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c\
	   ft_flag_utils.c\
	   ft_parse_utils.c\
	   ft_print_char.c\
	   ft_print_hex.c\
	   ft_print_int.c\
	   ft_print_ptr.c\
	   ft_print_str.c\
	   ft_print_uint.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)	clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all
	
.PHONY: all bonus clean fclean re
