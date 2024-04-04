.PHONY: all obj_files.o $(NAME) clean fclean re

NAME := get_next_line.a

all:	$(NAME)

# obj_files.o:
# 	@for file_source in ./*.c; do \
# 		file_obj="./$$(basename $${file_source%.c}).o"; \
# 		cc -Wall -Wextra -Werror -g -c "$${file_source}" -o "$${file_obj}"; \
# 	done

$(NAME):
	@cc -Wall -Wextra -Werror -g -c -D BUFFER_SIZE=1024 get_next_line.c -o get_next_line.o
	@cc -Wall -Wextra -Werror -g -c get_next_line_utils.c -o get_next_line_utils.o
	@ar rcs ./$(NAME) ./*.o

clean:
	@find ./ -name '*.o' -exec rm -f {} \;

fclean:	clean
	@find ./ -name '*.out' -exec rm -f {} \;
	@find ./ -name '*.a' -exec rm -f {} \;
	@find ./ -name '$(NAME)' -exec rm -f {} \;	

re:	fclean all

# bonus: libft libftprintf_bonus obj_files.o
# 	@ar x ./libft/libft.a
# 	@ar x ./bonus/libftprintf_bonus.a
# 	@rm ft_printf.o
# 	@ar rcs ./$(NAME) ./*.o
