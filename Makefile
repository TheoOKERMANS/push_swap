SRC = init_cut_string.c init_verif_arg.c init.c main.c solve_big.c solve_manager.c solve_small.c stack_push.c stack_reverse_rotate.c stack_rotate.c stack_swap.c utils_init.c utils_print.c utils_solver.c utils_solver2.c utils_solver3.c utils_verif_arg.c

OBJ= $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

$(NAME):
	make -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(SRC) libft/*.o

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	
re: fclean all