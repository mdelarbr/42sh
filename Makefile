# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/13 17:36:13 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/03/14 04:20:21 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re sobj uobj

NAME = 42sh

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIBFT_PATH = ./libft/
LIBFT_INC = ./libft/includes/

# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

LIB_NAME = libft.a

INC_NAME = forty_two.h

SRC_NAME = main.c print_shell.c struct.c ft_error.c free.c env.c

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix $(INC_PATH), $(INC_NAME))
LIB = $(addprefix $(LIBFT_PATH), $(LIB_NAME))
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

$(NAME): $(LIB) $(OBJ)
	@gcc $(42FLAGS) -o $@ $(OBJ) $(LIB)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null

$(LIB):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(42FLAGS) -I $(LIBFT_INC) -I $(INC_PATH) -o $@ -c $<

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH) 2> /dev/null

fclean:
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@rm -rf $(NAME) 2> /dev/null

re: fclean all
