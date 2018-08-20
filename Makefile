

NAME = ft_printf

SRCS = main.c libft/*.c

FLAGS = -Werror -Wall -Wextra
	
CC = gcc

OUT = -o $(NAME)

all :
	$(CC) $(FLAGS) $(SRCS) $(OUT)

fclean :
	rm -rf $(NAME)
