/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   termcaps.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 09:15:13 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 09:31:20 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

// # include "ft_printf.h"
# include "../libft/includes/ft_str.h"
# include "../libft/includes/ft_int.h"
# include "../libft/includes/ft_unix.h"
# include "../libft/includes/ft_printf.h"
# include "exec.h"
# include "check_error.h"
# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <dirent.h>

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
# define CTRLUP	2117425947
# define CTRLDOWN	2117491483
# define HOME	4741915
# define END	4610843
# define ALT_L    25115
# define ALT_R    26139

# define HIST		".42_history"
# define RESIZING	28
# define CTRL_C		2

typedef struct		s_pos
{
	int				act_co;
	int				act_li;
	int				start_li;
	int				start_co;
	int				max_co;
	int				max_li;
	int				ans_printed;
	char			*ans;
	char			*saved_ans;
	int				is_complete;
	int				was_incomplete;
	int				len_ans;
	int				let_nb;
	int				let_nb_saved;
	int				history;
	int				history_mode;
	int				history_loop;
	char			*prompt;
	int				len_prompt;
	int				start_select;
	char			debug;
	int				debug2;
	int				debug3;
	int				debug4;
	int				debug5;
    char            *debugchar;
	char			*toto;
	struct termios	old_term;
	struct termios	my_term;
}					t_pos;

typedef struct        s_htab
{
    struct s_htab    *next;
    struct s_htab    *prev;
    char            *content;
    int                content_no;
}                    t_htab;

typedef struct		s_inter
{
	int				sg_quote;
	int				db_quote;
	int				bracket;
	int				parenthesis;
	int				a_quote;
	int				db_and;
	int				pipe;
	int				db_pipe;
}					t_inter;

typedef struct			s_command
{
	char				*res;
	struct s_command	*next;
	struct s_command	*prev;
}						t_command;

typedef struct			s_select
{
	struct termios		my_term;
	struct termios		old_term;
}						t_select;

typedef struct			s_var
{
	char				*name;
	char				*data;
	int					type;
	struct s_var		*next;
}						t_var;

typedef struct			s_hist
{
	struct s_hist		*next;
	struct s_hist		*prev;
	char				*cmd;
	int					cmd_no;
}						t_hist;

void	print_info(t_pos *pos);
void	print_hist(t_pos *pos, t_hist *hist);


/*
** CALCUL_LINE
*/

int					get_len_with_lines(t_pos *pos);
int					go_to_let_nb_saved(t_pos *pos);
int					len_of_previous_line(t_pos *pos);
int					count_nb_line(t_pos *pos, int *j);
int					go_to_let_nb(t_pos *pos);

/*
** CHECK_ERROR
*/

int					check_term(void);

/*
** CHECK_INPUT.C
*/

t_hist				*check_input(unsigned char *buf, t_pos *pos, t_hist *hist);

/*
** ESCAPE_CODE
*/

t_hist				*escape_code(char *buf, t_pos *pos, t_hist *hist);
void				right_arrow(t_pos *pos);
void				left_arrow(t_pos *pos);

/*
** HISTORY.C
*/

void				free_t_hist(t_hist *hist);
void				init_t_hist(t_hist *hist);
t_hist				*add_list_back_hist(t_hist *hist);
t_hist				*create_history(t_pos *pos, t_hist *hist);

/*
** INITIALISATION_STOCK
*/

void				init_terminfo(t_pos *pos);
void				init_pos(t_pos *pos);
void				*stock(void *to_stock, int usage);

/*
** INPUT_IS_ENTRY
*/

int					find_missing_quote(char *str);
t_hist				*input_is_entry(t_pos *pos, t_hist *hist, char *buf);

/*
** INPUT_IS_PRINTABLE_CHAR
*/
void				prompt_is_on_last_char(t_pos *pos);
void				input_is_printable_char(t_pos *pos, char *buf);

/*
** INPUT_IS_REMOVE_CHAR
*/

void				input_is_delete(t_pos *pos);
int					input_is_backspace(t_pos *pos);

/*
** MOVE_THROUGHT_HISTORY
*/

t_hist				*move_through_history(t_hist *hist,
						t_pos *pos, char *usage);

/*
** PRINT_ANS
*/

void				prepare_to_print(t_pos *pos, char *buf);
void				print_ans(t_pos *pos, int i, int act_coi);

/*
** SEARCH_IN_HISTORY
*/

t_hist				*search_up_complete_in_history(t_hist *hist, t_pos *pos);
t_hist				*search_down_complete_in_history(t_hist *hist, t_pos *pos);

/*
** SIGNAL
*/

void				signal_list(void);

/*
** START_TERMCAPS
*/

char				*termcaps42sh(char *prompt, t_pos *pos, t_hist *hist);
void				print_prompt(t_pos *pos);

/*
** TAB_KEY
*/

void				input_is_tab(t_pos *pos);

/*
** TOOLS
*/

void				clean_at_start(t_pos *pos);
void				short_update(t_pos *pos, int len);
void				update_position(t_pos *pos);

/*
** COPY a mettre a la norme
*/

void	display_line(t_pos		*pos);
int		is_select(char *buf, t_pos *pos);
void	selected(t_pos *pos, char *buf);
void	selection_check(t_pos *pos, char *buf);

/*
** JUMP a mettre a la norme
*/

void	jump_left(t_pos *pos);
void	jump_right(t_pos *pos);
void	go_hard(t_pos *pos);
void	or_go_home(t_pos *pos);
int		nb_line(t_pos *pos);
void	jump_up(t_pos *pos);
void	jump_down(t_pos *pos);
void	find_jump(char *buf, t_pos *pos);

/*
*******************************************************************************
***							init_term.c										***
*******************************************************************************
*/
int						get_term(void);
int						check_term(void);

/*
*******************************************************************************
***							key_hook.c										***
*******************************************************************************
*/
int						ft_put_c(int c);

/*
*******************************************************************************
***								env.c										***
*******************************************************************************
*/
t_var					*init_env(char **env);
char					*init_name(char *src);

/*
*******************************************************************************
***								windows.c									***
*******************************************************************************
*/

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
int						ft_create_file(char *path);
int						ft_execute(char *exec, char **opt, char **env);
int						ft_file_exists(char *path);
int						ft_file_wrights(char *path);

char					*remove_char(char **str, int i);

/*
*******************************************************************************
***								ft_error.c									***
*******************************************************************************
*/
//void					free_all(t_all *all);
void					check_copy(unsigned char *buf, t_pos *pos);
void					free_env(t_var *var);

# include "lexeur.h"

#endif
