NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -I .

SRCS = main.c ft_push_swap.c \
	   printf/ft_itoa.c printf/ft_memchr.c printf/ft_printf.c\
	   printf/ft_print_character.c printf/ft_print_hex.c \
	   printf/ft_print_integer.c printf/ft_print_lowhex.c \
	   printf/ft_print_percent.c printf/ft_print_string.c \
	   printf/ft_print_uinteger.c printf/ft_print_upphex.c \
	   printf/ft_strlen.c \
	   operations/reverse_rotate.c operations/rotate.c operations/swap_push.c \
	   parse_err_handling/ft_arr_of_strjoin.c parse_err_handling/ft_get_nums.c \
	   utils/ft_atoi.c utils/ft_isdigit.c utils/ft_memcpy.c utils/ft_split.c \
	   utils/ft_strncmp.c utils/ft_strdup.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
