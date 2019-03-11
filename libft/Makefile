# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/25 12:55:34 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/03/09 13:50:45 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re sobj uobj

NAME = libft.a

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SSRC_PATH = $(addprefix $(SRC_PATH), str/)
SOBJ_PATH = $(addprefix $(OBJ_PATH), str/)


USRC_PATH = $(addprefix $(SRC_PATH), unix/)
UOBJ_PATH = $(addprefix $(OBJ_PATH), unix/)

ISRC_PATH = $(addprefix $(SRC_PATH), int/)
IOBJ_PATH = $(addprefix $(OBJ_PATH), int/)
# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

SINC_NAME = ft_str.h
SSRC_NAME = ft_bzero.c ft_isalpha.c ft_isascii.c ft_itoa.c ft_itoa_base.c\
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
			ft_putstr.c ft_putstr_fd.c ft_putstr_tab.c ft_str_remove_index.c ft_strcat.c ft_strcmp.c\
			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strjoin.c\
			ft_strjoin_free.c ft_strjoin_insert.c ft_strlen.c ft_strnew.c\
			ft_strstr.c ft_strsub.c ft_voidrev.c ft_voidswap.c

UINC_NAME = 
USRC_NAME =

IINC_NAME = ft_int.h
ISRC_NAME = ft_atoi.c ft_int_len_base.c ft_isdigit.c ft_isxdigit.c ft_putnbr.c\
			ft_putnbr_base.c ft_voidrev.c ft_voidswap.c

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

SOBJ_NAME = $(SSRC_NAME:.c=.o)
SOBJ = $(addprefix $(SOBJ_PATH), $(SOBJ_NAME))
SINC = $(addprefix $(INC_PATH), $(SINC_NAME))

UOBJ_NAME = $(USRC_NAME:.c=.o)
UOBJ = $(addprefix $(UOBJ_PATH), $(UOBJ_NAME))
UINC = $(addprefix $(INC_PATH), $(UINC_NAME))

IOBJ_NAME = $(ISRC_NAME:.c=.o)
IOBJ = $(addprefix $(IOBJ_PATH), $(IOBJ_NAME))
IINC = $(addprefix $(INC_PATH), $(IINC_NAME))


# **************************************************************************** #
#  									FLAG                                       #
# **************************************************************************** #

ifndef LFLAG
	LFLAG = -Wall -Werror -Wexta
endif

# **************************************************************************** #
# 									REGLES                                     #
# **************************************************************************** #

all : $(OBJ_PATH) $(NAME)

$(NAME): $(SOBJ) $(UOBJ) $(IOBJ)
	@ar rcs $(NAME) $(SOBJ) $(UOBJ) $(IOBJ)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(SOBJ_PATH) 2> /dev/null
	@mkdir -p $(UOBJ_PATH) 2> /dev/null
	@mkdir -p $(IOBJ_PATH) 2> /dev/null

$(SOBJ_PATH)%.o: $(SSRC_PATH)%.c $(SINC)
	gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<

$(UOBJ_PATH)%.o: $(USRC_PATH)%.c $(UINC)
	gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<

$(IOBJ_PATH)%.o: $(ISRC_PATH)%.c $(IINC)
	gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	
clean: 
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
