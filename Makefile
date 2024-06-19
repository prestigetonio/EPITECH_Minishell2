##
## EPITECH PROJECT, 2024
## makefile
## File description:
## emacs
##

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = mysh

SRC =	src/main.c       \
		src/minishell.c   \
		src/env.c          \
		src/cd_command.c    \
		src/clean.c          \
		src/exit_minishell.c  \
		src/init_env.c         \
		src/line_space.c        \
		lib/my_printf.c          \
		lib/my_strstr.c           \
		lib/my_putchar.c           \
		lib/my_put_nbr.c            \
		lib/my_put_nbru.c            \
		lib/my_strlen.c               \
		lib/my_strcat.c                \
		lib/my_str_to_word_array.c      \
		lib/my_str_to_word_array2.c      \
		lib/my_putstr.c                   \
		lib/my_strcmp.c                    \
		lib/my_strncmp.c                    \
		lib/my_strdup.c                      \
		lib/my_strcpy.c                       \
		src/setenv_command.c                   \
		src/unsetenv_command.c                  \
		src/separator.c                          \

OBJ =  $(SRC:.c=.o)

CFLAGS = -I ./include -Wall -g3

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@echo -e "$(YELLOW)■-■-■ COMPILATION GOOD ■-■-■$(NC)"
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3
	@echo -e "$(GREEN)■-■-■-■-■-■ GOOD ■-■-■-■-■$(NC)"

all : $(NAME)

clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f #*#
	@echo -e "$(GREEN)CLEAN$(NC)"

fclean : clean
	@echo -e "$(RED)CLEAN -> $(NAME)...$(NC)"
	rm -f $(NAME)
	@echo -e "$(GREEN)■-■-■-■-■ GOOD ■-■-■-■-■$(NC)"

re : fclean all
