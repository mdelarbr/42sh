# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <shthevak@student.42.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/13 17:36:13 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/03/29 16:21:09 by husahuc     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re sobj uobj

NAME = 42sh

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

INC_PATH = ./includes/
LIBFT_PATH = ./libft/
LIBFT_INC = ./libft/includes/

SRC_PATH = ./src/
OBJ_PATH = ./obj/

LAUNCH_S_PATH = $(addprefix $(SRC_PATH), launch/)
LAUNCH_O_PATH = $(addprefix $(OBJ_PATH), launch/)

EXEC_S_PATH = $(addprefix $(SRC_PATH), execute/)
EXEC_O_PATH = $(addprefix $(OBJ_PATH), execute/)

BUILTIN_S_PATH = $(addprefix $(SRC_PATH), builtin/)
BUILTIN_O_PATH = $(addprefix $(OBJ_PATH), builtin/)

# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

LIB_NAME = libft.a

LAUNCH_I_NAME = launch.h
LAUNCH_S_NAME = main.c print_shell.c struct.c ft_error.c free.c history.c\
		   alias.c exemple_redirection.c

EXEC_I_NAME = execute.h
EXEC_S_NAME = execute.c ft_execute.c ft_is_exec_verbose.c \

BUILTIN_I_NAME = builtin.h
BUILTIN_S_NAME = ft_cd.c ft_echo.c list_env.c ft_test.c ft_exit.c ft_type.c

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

LIB = $(addprefix $(LIBFT_PATH), $(LIB_NAME))

LAUNCH_O_NAME = $(LAUNCH_S_NAME:.c=.o)
LAUNCH_O = $(addprefix $(LAUNCH_O_PATH), $(LAUNCH_O_NAME))
LAUNCH_INC = $(addprefix $(INC_PATH), $(LAUNCH_I_NAME))

EXEC_O_NAME = $(EXEC_S_NAME:.c=.o)
EXEC_O = $(addprefix $(EXEC_O_PATH), $(EXEC_O_NAME))
EXEC_INC = $(addprefix $(INC_PATH), $(EXEC_I_NAME))

BUILTIN_O_NAME = $(BUILTIN_S_NAME:.c=.o)
BUILTIN_O = $(addprefix $(BUILTIN_O_PATH), $(BUILTIN_O_NAME))
BUILTIN_INC = $(addprefix $(INC_PATH), $(BUILTIN_I_NAME))

# **************************************************************************** #
#  									FLAG                                       #
# **************************************************************************** #

ifndef 42FLAG
	42FLAG = -Wall -Werror -Wexta
endif

# **************************************************************************** #
# 									REGLES                                     #
# **************************************************************************** #

all : $(OBJ_PATH) $(NAME)

$(NAME): $(LIB) $(LAUNCH_O) $(EXEC_O) $(BUILTIN_O)
	@gcc $(42FLAGS) -o $@ $(LIB) $(LAUNCH_O) $(BUILTIN_O) $(EXEC_O)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(LAUNCH_O_PATH) 2> /dev/null
	@mkdir -p $(EXEC_O_PATH) 2> /dev/null
	@mkdir -p $(BUILTIN_O_PATH) 2> /dev/null

$(LIB):
	@make -C $(LIBFT_PATH)

$(LAUNCH_O_PATH)%.o: $(LAUNCH_S_PATH)%.c $(LAUNCH_INC)
	@gcc $(42FLAGS) -I $(LIBFT_INC) -I $(INC_PATH) -o $@ -c $<

$(EXEC_O_PATH)%.o: $(EXEC_S_PATH)%.c $(EXEC_INC)
	@gcc $(42FLAGS) -I $(LIBFT_INC) -I $(INC_PATH) -o $@ -c $<

$(BUILTIN_O_PATH)%.o: $(BUILTIN_S_PATH)%.c $(BUILTIN_INC)
	@gcc $(42FLAGS) -I $(LIBFT_INC) -I $(INC_PATH) -o $@ -c $<

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH) 2> /dev/null

fclean:
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@rm -rf $(NAME) 2> /dev/null

re: fclean all
