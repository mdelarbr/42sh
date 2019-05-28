/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   termcaps.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 09:15:13 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 09:52:57 by vde-sain    ###    #+. /#+    ###.fr     */
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
# include "../libft/includes/ft_mem.h"
# include "exec.h"
# include "check_error.h"
# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <dirent.h>
# include "lexeur.h"

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

extern struct s_hist **ghist;

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
	char			*debugchar2;
	int				ctrl_search_history;
	char			*ctrl_hist_cmd;
	char			*toto;
	int				replace_hist;
	int				error;
	struct termios	old_term;
	struct termios	my_term;
}					t_pos;

typedef struct		s_htab
{
    struct s_htab	*next;
    struct s_htab	*prev;
    char			*content;
	int				content_type;
    int				content_no;
	int				lenght_max;
	int				matching_index;
}					t_htab;

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

typedef struct			ctrl_hist
{
		int				needle;
		int				act_co;
		int				act_li;
}						t_ctrl_hist;

typedef struct		s_tok
{
	int				quote;
	int				dquote;
	int				bquote;
	int				cmdand;
	int				cmdor;
	int				pipe;
	int				heredoc;
	char			*herestr;
	char			*fullheredoc;
	int				i;
	int				n;
	int				mode;
	int				nb_quote;
	int				nb_dquote;
	char			*dquote_d;
}					t_tok;

typedef struct			s_tokench
{
	char				*token;
	int					end;
	struct s_tokench	*next;
	struct s_tokench	*prev;
}						t_tokench;

void	print_info(t_pos *pos);
void	print_hist(t_pos *pos, t_hist *hist);
int		got_a_wildcard(char *name);

/*
** CALCUL_LINE
*/

int					get_len_with_lines(t_pos *pos);
int					go_to_let_nb_saved(t_pos *pos);
int					len_of_previous_line(t_pos *pos);
int					count_nb_line(t_pos *pos, int *j);
int					go_to_let_nb(t_pos *pos);

/*
**FT_ERRNO.C
*/

void				error_handling(t_pos *pos, char *variable, int err);

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

void				get_cursor_info(t_pos *pos, int *li, int *co, int i);
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

void				input_is_a_string_of_printable_char(t_pos *pos,
					char *to_add);
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

char				*termcaps42sh(t_pos *pos, t_hist *hist);
void				print_prompt(t_pos *pos);

/*
** TAB_KEY
*/

void				input_is_tab(t_pos *pos);

/*
** TAB_KEY_VAR
*/

t_htab			*looking_for_var(t_pos *pos, t_htab *htab, char **name);

/*
** TAB_KEY_CURRENT_DIR
*/

t_htab				*looking_for_current(t_pos *pos, t_htab *htab,
					char **path, char **name);

/*
** TAB_KEY_ALL_PATH
*/

t_htab			*looking_for_all(t_pos *pos, t_htab *htab, char **name);

/*
** TAB_KEY_TOOLS_CALCUL_PRINT
*/

int				is_a_directory(char *path, t_pos *pos);
int				get_word_index(t_pos *pos);
void			prepare_to_print_htab(t_pos *pos, t_htab *htabi);
void			print_htab(t_htab *htab, int max_word);
void			complete_with_space(t_htab *htab);

/*
** TAB_KEY_TOOLS_MANIP
*/

t_htab			*adjust_lenght_max(t_htab *htab);
char			*get_full_path(t_pos *pos);
char			*get_correct_path(char *path);
void			reduce_ans(t_pos *pos, char *name);
void			add_slash_on_ans(t_pos *pos);

/*
** TAB_KEY_STRUCT
*/

void			free_htab(t_htab *htab);
t_htab			*add_list_back_htab(t_htab *htab);
t_htab			*add_list_back_sort_htab(t_htab *head, t_htab *ls, int loop);
t_htab			*fill_new_htab(t_htab *htab, t_htab *neww, int match);

/*
** TAB_KEY_AUTO_COMPLETE
*/


int			wildcard_match(char *s1, char *s2);

t_htab			*get_current_match(t_htab *htab, char *name, int wildcard);
void			auto_complete(t_pos *pos, t_htab *htab, char *name);
t_htab			*prepare_auto_complete(t_pos *pos, t_htab *htab, char *name);
t_htab			*get_intelligent_match(t_htab *htab, char *name);

/*
** TAB_KEY_SORT
*/

t_htab		*sort_list_htab(t_htab *head);

/*
** TOOLS
*/

void				clean_at_start(t_pos *pos);
void				short_update(t_pos *pos, int len);
void				update_position(t_pos *pos);
int					is_in_selection_area(int i, t_pos *pos);

/*
** COPY a mettre a la norme
*/
void			print_from_begin(t_pos *pos);
void			display_line(t_pos*pos);
void			selection_check(t_pos *pos, char *buf);
void			select_right(t_pos *pos);
void			select_left(t_pos		*pos);

/*
** COPY_TOOLS
*/
int				is_select(char *buf, t_pos *pos);
void			selected(t_pos *pos, char *buf);
void			clear_and_print(t_pos *pos);
void			save_char(t_pos *pos);

/*
** CUT
*/
void			check_copy(unsigned char *buf, t_pos *pos);
void			copy(t_pos *pos);
void			paste(t_pos *pos);
void			cut_char(t_pos *pos);
char			*remove_cut(char *str, int start, int end);

/*
** JUMP a mettre a la norme
*/

void	find_jump(char *buf, t_pos *pos);

/*
**JUMP_UP_DOWN.C
*/

void	jump_down(t_pos *pos);
void	jump_up(t_pos *pos);

/*
** HISTORY_EXPANSION.C
*/

t_hist			*check_history_expansion(t_pos *pos, char *ans, t_hist *hist);
t_hist			*exit_history_expansion(t_hist *hist, char *ans, t_pos *pos);
t_hist			*replace_expansion_by_value(t_pos *pos, char **ans,
				t_hist *hist, int *i);
char			*get_expansion_content(char *ans, int i);
int				get_expansion_length(char *ans, int i);

/*
**HISTORY_EXPANSION_FREE.C
*/

t_hist			*no_expansion_found(char **expansion, char **new_ans,
				t_hist *hist);
char			*new_ans_not_valid(char **ans, char *new_ans, int *i);
char			*filling_ans_with_new_ans(t_pos *pos, char *new_ans, char **ans,
				int end_exp);

/*
**HISTORY_EXPANSION_TYPES.C
*/

t_hist			*get_expansion_type(char *expansion, t_hist *hist,
				char **new_ans, int *i);
t_hist			*double_exclamation_expansion(char **new_ans, t_hist *hist,
				char *expansion);
t_hist			*word_finding_expansion(char **new_ans, t_hist *hist,
				char *expansion);
t_hist			*negative_number_expansion(char **new_ans, t_hist *hist,
				char *expansion);
t_hist			*number_expansion(char **new_ans, t_hist *hist,
				char *expansion, t_pos *pos);

/*
** token_init.c
*/

t_tokench	*add_list_back_tok_next(t_tokench *tok);
void		maj_token(t_tokench *tok, char *c);
void		init_tok(t_tok *in);

/*
** token.c
*/

void	check_token(t_pos *pos, t_tok *in, t_tokench *tok);
void	init_tok(t_tok *in);

/*
** token_check_open.c
*/

void		check_first_token(t_pos *pos, t_tok *in, t_tokench *tok);

/*
** token_check_close.c
*/

int			check_close_nothing(t_pos *pos, t_tok *in);
int			check_close_nothing2(t_pos *pos, t_tok *in);
int			check_close_tree(t_pos *pos, t_tok *in);
void		check_mode_1_2(t_tok *in, t_tokench *tok, char *c);
t_tokench	*check_close(t_tokench *tok, char *c, t_tok *in);

/*
** token_heredoc_open.c
*/

void		check_heredoc(t_pos *pos, t_tok *in, t_tokench *tok);

/*
** token_heredoc_close.c
*/

void		heredoc_1(t_pos *pos, t_tok *in, t_tokench *tok);

/*
** token_free.c
*/

void		free_heredoc(t_tok *in);
void		free_all_check_token(t_tok *in, t_tokench *tok);

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
void					free_env(t_var *var);

/*
 * **    CONTROL_SEARCH_HISTORY.C
 * */

t_hist					*control_search_history(t_pos *pos, t_hist *hist,
						unsigned char *buf);
t_hist					*search_occurence_in_history(t_pos *pos, t_hist *hist,
						t_ctrl_hist *ctrl);
void                    needle_found_in_history(t_pos *pos, t_hist *hist,
						t_ctrl_hist *ctrl);
t_hist					*exiting_control_mode(t_pos *pos, t_hist *hist);
int						get_pos_strstr(char *str, char *tofind, int i, int j);

/*
**CONTROL_SEARCH_HISTORY_CALCUL_LINES.C
*/

void					get_right_coordinates_found(t_pos *pos, t_hist *hist,
						t_ctrl_hist *ctrl);
int						count_cmd_line_len(t_pos *pos, char *ans, int act_co);
void					count_ctrl_col_and_line(t_pos *pos, char *ans,
						t_ctrl_hist *ctrl, int needle);

/*
**CONTROL_SEARCH_HISTORY_CALCUL_POS.C
*/

void					get_right_coordinates_not_found(t_pos *pos, t_ctrl_hist
						*ctrl);
void					get_pos_coordinates_right_again(t_pos *pos);




void					check_copy(unsigned char *buf, t_pos *pos);

#endif
