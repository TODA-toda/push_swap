NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_character.c ft_print_percent.c ft_print_string.c \
	   ft_print_integer.c ft_print_uinteger.c ft_print_lowhex.c \
	   ft_print_upphex.c ft_print_hex.c ft_itoa.c ft_memchr.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
