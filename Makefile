# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/04 18:02:46 by mjalenqu     #+#   ##    ##    #+#        #
#    Updated: 2019/04/16 13:09:13 by mdelarbr    ###    #+. /#+    ###.fr      #
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
			lexeur/fill_fd.c lexeur/lexeur.c lexeur/fill_lexeur.c lexeur/redirection.c \
			replace/replace.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = shell.h

INC = $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAG += -Wall -Werror -Wextra -g3 -fsanitize=address
FLAG_END = -lcurses
NORME = norminette

BLUE=\033[0;38;5;123m
DARK_BLUE = \033[0;38;5;110m
GREEN = \033[0;32m
LIGHT_GREEN = \033[1;38;5;121m
FLASH_GREEN = \033[33;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ) Makefile
	@make -C libft
	@echo "$(YELLOW)Libft$(RESET):\t...$(GREEN)\t[OK]"
	@gcc $(FLAG) -o $@ $(OBJ) $(FLAG_END) $(LIB_PATH) -Iinclude
	@echo "$(YELLOW)$(NAME)$(RESET):\t...$(GREEN)\t[OK]"

$(OBJ_PATH):
	@mkdir -p obj 2> /dev/null
	@mkdir -p obj/hachage 2> /dev/null
	@mkdir -p obj/line_edit 2> /dev/null
	@mkdir -p obj/lexeur 2> /dev/null
	@mkdir -p obj/replace 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAG) -g -I $(INC) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)
	@echo ".o\tof\t$(YELLOW)$(NAME)$(RESET):\t$(RED)[-]$(RESET)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "./$(NAME)\tof\t$(YELLOW)$(NAME)$(RESET):\t$(RED)[-]\n"

re : fclean all
