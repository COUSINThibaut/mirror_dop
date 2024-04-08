##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## bs my_ls
##

SRC	=	src/mysh.c				\
		lib/my/my_show_word_array.c		\
		lib/my/my_putchar.c			\
		lib/my/my_putstr.c			\
		lib/my/my_str_to_word_array.c		\
		lib/my/my_str_to_word_array_path.c	\
		lib/my/my_strcat.c			\
		lib/my/my_strdup.c			\
		lib/my/my_strlen.c			\
		lib/my/my_strcpy.c			\
		lib/my/my_strcmp.c			\
		lib/my/my_strncat.c			\
		lib/my/my_getnbr.c			\
		lib/my/my_str_to_word_cmd_array.c	\
		src/cd.c				\
		src/get_line_env.c			\
		src/env_fonctions.c			\
		src/clean_str.c				\
		src/handling_command.c			\
		src/error_handling.c			\
		src/exec_cmd.c				\
		src/gestion_struct.c			\
		src/right_redirection.c			\

SRCtest	=	tests/test_mysh1.c			\
		src/gestion_struct.c			\
		lib/my/my_show_word_array.c		\
		lib/my/my_putchar.c			\
		lib/my/my_putstr.c			\
		lib/my/my_str_to_word_array.c		\
		lib/my/my_str_to_word_array_path.c	\
		lib/my/my_strcat.c			\
		lib/my/my_strdup.c			\
		lib/my/my_strlen.c			\
		lib/my/my_strcpy.c			\
		lib/my/my_strcmp.c			\
		lib/my/my_strncat.c			\
		lib/my/my_getnbr.c			\
		lib/my/my_str_to_word_cmd_array.c	\
		src/clean_str.c				\

OBJtest	=	$(SRCtest:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

NAMEtest=	unit_tests

CFLAGS	=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(OBJ) $(CLIB)

$(NAMEtest):	$(OBJtest)
	gcc -g -o $(NAMEtest) $(OBJtest) $(CLIB) -lcriterion

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

tests_run:	$(NAMEtest)
