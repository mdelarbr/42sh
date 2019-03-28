/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:55:39 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 10:11:11 by mjalenqu    ###    #+. /#+    ###.fr     */
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

typedef struct			s_count
{
	int					quote;
	int					dquote;
}						t_count;


typedef struct			s_wind
{
	int					term_fd;
	int					max_col;
	int					max_line;
	int					pos_line;
	int					pos_col;
}						t_wind;

typedef struct			s_select
{
	struct termios		my_term;
	struct termios		old_term;
}						t_select;

typedef struct			s_history
{
	int					len;
	char				*cmd;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct			s_env
{
	char				*name;
	char				*data;
	int					type;
	struct s_env		*next;
}						t_env;

typedef struct			s_all
{
	t_wind				*wind;
	t_history			*history;
	t_history			*last;
	t_history			*first;
	t_env				*env;
}						t_all;
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

# define HIST	".42_history"
# define POS	select->pos
# define OTERM	select->old_term
# define MTERM	select->my_term
# define CMD	all->history->cmd
# define HNEXT	all->history->next
# define HPREV	all->history->prev
# define COL	all->wind->max_col
# define LINE	all->wind->max_line
# define PCOL	all->wind->pos_col
# define PLINE	all->wind->pos_line
# define FD		all->wind->term_fd
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
char					*key_hook(t_all *all);
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

/*
*******************************************************************************
***								ft_error.c									***
*******************************************************************************
*/
void					ft_error_quit(int nb);
void					ft_error(int nb);

/*
*******************************************************************************
***								history.c									***
*******************************************************************************
*/
void					get_history(t_history **history);
void					read_history(t_history **history);
int						ft_create_file(char *path);
int						ft_execute(char *exec, char **opt, char **env);
int						ft_file_exists(char *path);
int						ft_file_wrights(char *path);

void					do_up(t_all *all, char **res);
void					do_down(t_all *all);
void					do_left(t_all *all);
void					do_right(t_all *all);
void					do_back(t_all *all);
void					do_del(t_all *all);
void					do_tab(t_all *all);
char					*le_truc_qui_boucle(t_all *all);
#endif
