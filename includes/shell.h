/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:55:39 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 00:29:19 by mjalenqu    ###    #+. /#+    ###.fr     */
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

typedef struct	s_wind
{
	int					term_fd;
	int					max_col;
	int					max_line;
	int					pos_line;
	int					pos_col;
}				t_wind;

typedef struct	s_select
{
	struct termios		my_term;
	struct termios		old_term;
}				t_select;

typedef struct	s_history
{
	char				*cmd;
	struct s_history	*next;
	struct s_history	*prev;
}				t_history;

typedef struct		s_env
{
	char				*name;
	char				*data;
	int					type;
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
# define HPREV	history->prev
# define COL	wind->max_col
# define LINE	wind->max_line
# define PCOL	wind->pos_col
# define PLINE	wind->pos_line
# define FD		wind->term_fd
# define BSIZE 6

/*
*******************************************************************************
***							init_term.c										***
*******************************************************************************
*/
t_select				*init_term(t_select *select);

/*
*******************************************************************************
***							key_hook.c										***
*******************************************************************************
*/
int						key_hook(t_wind *wind);
int						ft_put_c(int c);

/*
*******************************************************************************
***								env.c										***
*******************************************************************************
*/
t_env					*init_env(char **env);
char					*init_name(char *src);
char					*init_data(char *src);

/*
*******************************************************************************
***								windows.c									***
*******************************************************************************
*/
t_wind					*init_wind(void);

#endif
