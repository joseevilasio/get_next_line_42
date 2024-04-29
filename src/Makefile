.PHONY: all $(NAME) clean fclean re

NAME := get_next_line.a

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

# SRCS := get_next_line.c  get_next_line_utils.c \

# OBJS := $(SRCS.c=.o)

all:	$(NAME)

# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) -c $*.c -o $@

run:
	$(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o
	$(CC) $(CFLAGS) -c get_next_line_utils.c -o get_next_line_utils.o

$(NAME): run
	$(AR) $(NAME) ./*.o

clean:
	rm -f ./*.o

fclean:	clean
	rm -f ./*.a

re:	fclean all
