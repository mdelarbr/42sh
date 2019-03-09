/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:55:39 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 11:07:51 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** includes **
*/
# include <curses.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

/*
** structures **
*/
typedef struct	s_select
{
	int					pos;
	struct termios		my_term;
	struct termios		old_term;
}				t_select;

typedef struct	s_history
{
	char				*cmd;
	struct s_history	*next;
}				t_history;

typedef struct		s_env
{
	char				*name;
	char				*data;
	struct s_env		*next;
}					t_env;

/*
** color **
*/
# define RESET "\033[00m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BPURPLE "\033[1;35m"
# define BCYAN "\033[1;36m"

/*
** key **
*/
# define UP     4283163
# define DOWN   4348699
# define LEFT   4479771
# define RIGHT  4414235
# define TAB    9
# define DEL    2117294875
# define BACK   127
# define ENTER  10
# define ESCAPE 27

# define POS	select->pos
# define OTERM	select->old_term
# define MTERM	select->my_term
# define CMD	history->cmd
# define HNEXT	history->next
# define BSIZE 6

/*
*******************************************************************************
***							init_term.c										***
*******************************************************************************
*/
t_select				*init_term(t_select *select);

/*
*******************************************************************************
***							init_term.c										***
*******************************************************************************
*/
int						key_hook(void);

/*
*******************************************************************************
***								env.c										***
*******************************************************************************
*/
t_env					*init_env(char **env);
char					*init_name(char *src);
char					*init_data(char *src);
#endif
