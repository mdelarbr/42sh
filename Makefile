# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/04 18:02:46 by mjalenqu     #+#   ##    ##    #+#        #
#    Updated: 2019/04/16 07:41:29 by mjalenqu    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = 21sh

LIB_PATH = libft/libft.a
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC_NAME =	line_edit/main.c line_edit/init_term.c line_edit/key_hook.c line_edit/env.c line_edit/windows.c\
			line_edit/ft_error.c line_edit/history.c\
			line_edit/arrow.c line_edit/other_key.c line_edit/ft_free.c lexeur/back_slash.c lexeur/error.c\
			lexeur/fill_fd.c lexeur/lexeur.c lexeur/fill_lexeur.c\
			lexeur/redirection.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = shell.h

INC = $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAG += -Wall -Werror -Wextra -g3 -fsanitize=address
FLAG_END = -lcurses
NORME = norminette

BLUE=\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[0;38;5;110m
GREEN = \033[0;38;5;111m
LIGHT_GREEN = \033[1;38;5;121m
LIGHT_RED = \033[1;31;5;121m
FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ) Makefile
	@echo "\n\n$(LIGHT_GREEN)Compilation de la libft : "
	@make -C libft
	@gcc $(FLAG) -o $@ $(OBJ) $(FLAG_END) $(LIB_PATH) -Iinclude
	@echo "$(FLASH_GREEN)$(NAME) compilé et prêt à l'usage !\n"

$(OBJ_PATH):
	@mkdir -p obj 2> /dev/null
	@mkdir -p obj/hachage 2> /dev/null
	@mkdir -p obj/line_edit 2> /dev/null
	@mkdir -p obj/lexeur 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAG) -g -I $(INC) -o $@ -c $<
	@echo "$(LIGHT_RED).\c"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re : fclean all
