SRC = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c

OBJ= $(SRC:.c=.o)
NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

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
TXT_DONE=\033[0;32m
#-------------------------

$(NAME):
	@printf "$(TXT_TITLE)Libft\n"
	@printf "$(TXT_COMPILING) Compiling files\n"
	@printf "$(TXT_BLACK)"
	@for file in $(SRC) ; do \
		printf " $$file\n" ; \
		$(CC) $(FLAGS) -c $$file ; \
	done
	@printf "$(TXT_COMPILING) Compiling library...\n"
	@printf "$(TXT_BLACK) $(NAME)\n"
	@ar rc $(NAME) $(OBJ)
	@printf "$(TXT_DONE)DONE\n$(TXT_NC)"

all: $(NAME)

clean:
	@printf "$(TXT_TITLE)Libft\n"
	@printf "$(TXT_DELETING) Deleting files\n"
	@printf "$(TXT_BLACK)"
	@for file in $(OBJ) ; do \
		printf " $$file\n" ; \
		rm -f $$file ; \
	done
	@printf "$(TXT_DONE)DONE\n$(TXT_NC)"

fclean:
	@printf "$(TXT_TITLE)Libft\n"
	@printf "$(TXT_DELETING) Deleting files\n"
	@printf "$(TXT_BLACK)"
	@for file in $(OBJ) ; do \
		printf " $$file\n" ; \
		rm -f $$file ; \
	done
	@printf "$(TXT_DELETING) Deleting library\n"
	@printf "$(TXT_BLACK) $(NAME)\n"
	@rm -f $(NAME)
	@printf "$(TXT_DONE)DONE\n$(TXT_NC)"
	
re: fclean all