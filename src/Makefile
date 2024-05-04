.PHONY: all $(NAME) clean fclean re bonus

NAME := get_next_line.a

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

# SRCS := get_next_line.c  get_next_line_utils.c \

# OBJS := $(SRCS.c=.o)

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o
	$(CC) $(CFLAGS) -c get_next_line_utils.c -o get_next_line_utils.o
	$(AR) $(NAME) ./*.o

bonus:
	$(CC) $(CFLAGS) -c get_next_line_bonus.c -o get_next_line_bonus.o
	$(CC) $(CFLAGS) -c get_next_line_utils_bonus.c -o get_next_line_utils_bonus.o
	$(AR) $(NAME) ./*.o

clean:
	rm -f ./*.o

fclean:	clean
	rm -f ./*.a

re:	fclean all
