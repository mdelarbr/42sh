# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/04 18:02:46 by mjalenqu     #+#   ##    ##    #+#        #
#    Updated: 2019/04/10 13:01:10 by mjalenqu    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = 21sh

LIB_PATH = libft/libft.a
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC_NAME =	main.c init_term.c key_hook.c env.c windows.c ft_error.c history.c\
			arrow.c other_key.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = shell.h

INC = $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAG += -Wall -Werror -Wextra -g3 #-fsanitize=address
FLAG_END = -lcurses
NORME = norminette

BLUE=\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[0;38;5;110m
GREEN = \033[0;38;5;111m
LIGHT_GREEN = \033[1;38;5;121m
FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ) Makefile
	@echo "$(LIGHT_GREEN)Compilation de la libft : "
	@make -C libft
	gcc $(FLAG) -o $@ $(OBJ) $(FLAG_END) $(LIB_PATH) -Iinclude
	@echo "$(FLASH_GREEN)$(NAME) compilé et prêt à l'usage !\n"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	gcc $(FLAG) -g -I $(INC) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re : fclean all