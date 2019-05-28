# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mjalenqu <mjalenqu@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/04 18:02:46 by mjalenqu     #+#   ##    ##    #+#        #
#    Updated: 2019/05/28 10:07:58 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = 21sh

LIB_PATH = libft/libft.a
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC_LINE = $(addprefix line_edit/, \
				calcul_line.c check_error.c check_input.c control_search_history_calcul_pos.c\
				control_search_history.c control_search_history_calcul_lines.c \
				copy_tools.c copy.c cut.c env.c escape_code.c ft_errno.c\
				history_expansion_free.c history_expansion.c history_expansions_types.c\
				history.c initialisation_stock.c input_is_entry.c tools.c\
				input_is_printable_char.c input_is_remove_char.c jump_up_down.c jump.c\
				move_through_history.c print_ans.c search_in_history.c signal.c tab_key_var.c\
				start_termcaps.c tab_key.c tab_key_all_path.c tab_key_auto_complete.c tab_key_current_dir.c\
				tab_key_sort.c tab_key_struct.c tab_key_tools_calcul_print.c tab_key_tools_manip.c\
				token.c token_check_close.c token_check_open.c token_free.c token_heredoc_close.c\
				token_heredoc_open.c token_init.c)

SRC_LEX = $(addprefix lexeur/, \
				back_slash.c double_quote.c error.c fill_fd.c fill_lexeur.c lexeur.c redirection.c)

SRC_EXEC = $(addprefix exec/, \
				alias.c builtins.c exec_main.c exec.c option_exec.c process.c tools.c)

SRC_REP = $(addprefix replace/, \
				alias.c env_replace.c replace.c tool.c var_replace.c)
				
SRC_MAIN = $(addprefix main/, main.c)

SRC_NAME = $(SRC_EXEC) $(SRC_LEX) $(SRC_LINE) $(SRC_MAIN) $(SRC_REP)
SRC_NAME =	main/main.c\
			line_edit/calcul_line.c line_edit/check_input.c line_edit/escape_code.c line_edit/history.c line_edit/init_termcaps.c\
			line_edit/input_is_entry.c line_edit/input_is_printable_char.c line_edit/jump.c line_edit/move_through_history.c\
			line_edit/search_in_history.c line_edit/env.c line_edit/input_is_remove_char.c line_edit/print_ans.c\
			lexeur/back_slash.c lexeur/error.c\
			lexeur/fill_fd.c lexeur/lexeur.c lexeur/fill_lexeur.c lexeur/redirection.c \
			replace/replace.c replace/env_replace.c replace/var_replace.c replace/tool.c replace/alias.c\
			exec/exec.c exec/process.c exec/exec_main.c exec/tools.c exec/builtins.c exec/option_exec.c exec/alias.c \
			builtin/ft_test.c builtin/ft_test_int.c builtin/ft_echo.c builtin/tool.c builtin/ft_cd.c \
			builtin/ft_set.c builtin/ft_type.c builtin/ft_export.c builtin/ft_unset.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = termcaps.h

INC = $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

FLAG += -Wall -Werror -Wextra -o3 -g3# -fsanitize=address
FLAG_END = -lcurses
NORME = norminette

BLUE=\033[0;38;5;123m
DARK_BLUE = \033[0;38;5;110m
GREEN = \033[0;32m
LIGHT_GREEN = \033[1;38;5;121m
LIGHT_YELLOW = \033[1;33;5;121m
LIGHT_RED = \033[1;31;5;121m
FLASH_GREEN = \033[33;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ) Makefile
	@make -C libft
	@echo "$(YELLOW)Libft$(RESET):\t...$(GREEN)\t[OK]"
	@gcc $(FLAG) -o $@ $(OBJ) $(FLAG_END) $(LIB_PATH) -I include
	@echo "$(YELLOW)$(NAME)$(RESET):\t...$(GREEN)\t[OK]"

$(OBJ_PATH):
	@mkdir -p obj 2> /dev/null
	@mkdir -p obj/hachage 2> /dev/null
	@mkdir -p obj/line_edit 2> /dev/null
	@mkdir -p obj/lexeur 2> /dev/null
	@mkdir -p obj/replace 2> /dev/null
	@mkdir -p obj/exec 2> /dev/null
	@mkdir -p obj/builtin 2> /dev/null
	@mkdir -p obj/main 2> /dev/null
	@mkdir -p obj/ft_printf 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAG) -g -I $(INC_PATH) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)
	@echo ".o\tof\t$(YELLOW)$(NAME)$(RESET):\t$(RED)[-]$(RESET)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "./$(NAME)\tof\t$(YELLOW)$(NAME)$(RESET):\t$(RED)[-]\n"

re : fclean all
