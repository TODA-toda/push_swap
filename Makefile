NAME = libpush_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(SRCS)

$(OBJS): $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean clean

.PHONY: all clean fclean re
