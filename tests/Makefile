.PHONY: all $(NAME) clean fclean re bonus

GNL := get_next_line.a

LIBFT = libft.a

SIZE = 42

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

$(GNL):
	@make -s bonus -C ../src

$(LIBFT):
	@make -s all -C ../libft

clean:
	@rm -f ./*.o
	# @rm -f ./main

fclean:
	@rm -f ./*.a
	@make -s fclean -C ../src
	@make -s fclean -C ../libft

run: $(GNL) $(LIBFT)
	@$(CC) $(CFLAGS) -DBUFFER_SIZE=$(SIZE) main.c -o main ./../src/$(GNL) ./../libft/$(LIBFT)
	@valgrind -q --leak-check=full --track-origins=yes ./main
	@make fclean