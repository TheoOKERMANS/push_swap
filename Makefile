SRC = init_cut_string.c \
init_verif_arg.c \
init.c \
main.c \
solve_big.c \
solve_manager.c \
solve_small.c \
stack_push.c \
stack_reverse_rotate.c \
stack_rotate.c stack_swap.c \
utils_init.c \
utils_print.c \
utils_solver.c \
utils_solver2.c \
utils_solver3.c \
utils_verif_arg.c

OBJ= $(SRC:.c=.o)
LIBFT = -L libft/ -lft
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

#-----------TXT-----------
TXT_BLACK=\033[0;30m
TXT_RED=\033[0;31m
TXT_GREEN=\033[0;32m
TXT_ORANGE=\033[0;33m
TXT_BLUE=\033[0;34m
TXT_PURPLE=\033[0;35m
TXT_CYAN=\033[0;36m
TXT_LIGHT_GRAY=\033[0;37m

TXT_NC=\033[0m
TXT_TITLE=\033[1;35m
TXT_COMPILING=\033[1;34m
TXT_DELETING=\033[1;31m
TXT_DONE=\033[1;32m
#-------------------------

$(NAME):
	@make -C ./libft --no-print-directory
	@printf "$(TXT_TITLE)Push Swap\n"
	@printf "$(TXT_COMPILING) Compiling files\n"
	@printf "$(TXT_BLACK)"
	@for file in $(addprefix src/, $(SRC)) ; do \
		printf " $$file\n" ; \
		$(CC) $(FLAGS) -c $$file ; \
	done
	@printf "$(TXT_COMPILING) Compiling program...\n"
	@printf "$(TXT_BLACK) $(NAME)\n"
	@$(CC) -o $(NAME) $(FLAGS) $(addprefix src/, $(SRC)) $(LIBFT);
	@printf "$(TXT_DONE)DONE\n$(TXT_NC)"

all: $(NAME)

clean:
	@make clean -C ./libft --no-print-directory
	@printf "$(TXT_TITLE)Push Swap\n"
	@printf "$(TXT_DELETING) Deleting files\n"
	@printf "$(TXT_BLACK)"
	@for file in $(OBJ) ; do \
		printf " $$file\n" ; \
		rm -f $$file ; \
	done
	@printf "$(TXT_DONE)DONE\n$(TXT_NC)"

fclean:
	@make fclean -C ./libft --no-print-directory
	@printf "$(TXT_TITLE)Push Swap\n"
	@printf "$(TXT_DELETING) Deleting files\n"
	@printf "$(TXT_BLACK)"
	@for file in $(OBJ) ; do \
		printf " $$file\n" ; \
		rm -f $$file ; \
	done
	@printf "$(TXT_DELETING) Deleting program\n"
	@printf "$(TXT_BLACK) $(NAME)\n"
	@rm -f $(NAME)
	@printf "$(TXT_DONE)DONE\n$(TXT_NC)"
	
re: fclean all