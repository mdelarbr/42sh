/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 09:15:13 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 13:13:53 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>





typedef struct		s_hist
{
	struct s_hist	*next;
	struct s_hist	*prev;
	char			*cmd;
	int				cmd_no;
}					t_hist;

int		get_next_line_42sh(const int fd, char **line);
char	*termcaps42sh(char *prompt, int error, t_pos *pos, t_hist *hist);

/*
**INIT_FT_SELECT.C
*/

int					main(void);
void				init_terminfo(t_pos *pos);
int					init_pos(t_pos *pos, char *buf);
void				get_start_info(char *buf, t_pos *pos);
int					check_term(void);

/*
**CHECK_INPUT.C
*/

void				free_t_hist(t_hist *hist);
t_hist				*check_input(char *buf, t_pos *pos, t_hist *hist);

/*
**INPUT_IS_REMOVE_CHAR.C
*/

void				input_is_backspace(t_pos *pos);
void				remove_char_ans(t_pos *pos);
void				input_is_delete(t_pos *pos);

/*
**INPUT_IS_PRINTABLE_CHAR.C
*/

void				prompt_is_on_last_char(t_pos *pos);
void				input_is_printable_char(t_pos *pos, char *buf);

/*
**ESCAPE_CODE.C
*/

t_hist				*escape_code(char *buf, t_pos *pos, t_hist *hist);
void				left_arrow(char *buf, t_pos *pos);
void				right_arrow(char *buf, t_pos *pos);
int					len_of_previous_line(t_pos *pos);

/*
** INPUT_IS_ENTRY.C
*/

t_hist				*input_is_complete(t_pos *pos, t_hist *hist);
t_hist				*input_is_entry(t_pos *pos, t_hist *hist, char *buf);

/*
**HANDLE_ANS.C
*/

void				prepare_to_print(t_pos *pos, char *buf);
void				fill_char_ans(char *buf, t_pos *pos);
void				remove_char_ans(t_pos *pos);
int					get_len_with_lines(t_pos *pos);

/*
**HISTORY.C
*/

void				init_t_hist(t_hist *hist);
t_hist				*create_history(t_pos *pos, t_hist *hist);
t_hist				*add_list_back_hist(t_hist *hist);
void				update_position(t_pos *pos, char *cmd);

/*
**MOVE_THROUGHT_HISTORY.C
*/


t_hist				*move_through_history(t_hist *hist, t_pos *pos, char *usage, char *buf);

/*
**SEARCH_IN_HISTORY.C
*/

t_hist		*search_up_complete_in_history(t_hist *hist, t_pos *pos);
t_hist		*search_down_complete_in_history(t_hist *hist, t_pos *pos);
t_hist		*search_up_incomplete_in_history(t_hist *hist, t_pos *pos);
t_hist		*search_down_incomplete_in_history(t_hist *hist, t_pos *pos);

/*
**TERMCAPS_TOOLS.C
*/

void				print_info(t_pos *pos);
void				print_hist(t_pos *pos, t_hist *hist);

/*
**CALCUL_LINE.C
*/

int					go_to_let_nb_saved(t_pos *pos);
int					count_nb_line(t_pos *pos, int *j);

#endif
