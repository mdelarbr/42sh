# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 11:36:22 by tprzybyl     #+#   ##    ##    #+#        #
#    Updated: 2019/01/11 09:21:04 by mjalenqu    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
SRC=ft_atoi.c \
	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	ft_lstmap.c ft_lstnew.c ft_lstpush.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_lstlen.c ft_islower.c ft_isupper.c ft_strfjoin.c ft_strclen.c ft_strfsub.c \
	ft_strnclen.c ft_strcchr.c ft_arrstrdel.c ft_putstr2.c ft_putcolor.c ft_putsnb.c \
	ft_putcolor2.c get_next_line.c ft_free_tab.c ft_strjoin_insert.c ft_remove_c.c

FLAGS= -Wall -Wextra -Werror -g3 #-fsanitize=address

OBJ = $(subst .c,.o,$(SRC))

BLUE = \033[0;38;5;123m


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\n"
	@ranlib $(NAME)

%.o: %.c libft.h
	@gcc $(FLAGS) -o $@ -c $<
	@echo "$(BLUE).\c"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
