/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 14:41:17 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 11:14:59 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void		remove_char_ans(t_pos *pos)
{
	char	*swap;

	swap = ft_strnew(pos->let_nb);
	swap = ft_strncpy(swap, pos->ans, pos->let_nb - 1);
	if (pos->let_nb < pos->len_ans)
	{
		swap = ft_strjoinf(swap, pos->ans + pos->let_nb, 1);
		free(pos->ans);
	}
	pos->ans = swap;
}

void            input_is_backspace(t_pos *pos)
{
	if (pos->act_co == 0 && pos->act_li > pos->start_li)
	{
		pos->act_li -= 1;
		if (pos->ans[pos->let_nb - 1] == '\n')
			pos->act_co = len_of_previous_line(pos);
		else
			pos->act_co = pos->max_co - 1;
	}
	else if (pos->is_complete == 0 && pos->let_nb > 0 &&
		pos->ans[pos->let_nb - 1] == '\n' && pos->act_co == pos->len_prompt)
		return ;
	else
		pos->act_co -= pos->act_co == 0 ? 0 : 1;
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li),
		1, ft_putchar);
	remove_char_ans(pos);
	pos->let_nb -= 1;
	pos->len_ans -= 1;
}

void		update_history(t_pos *pos, t_hist *hist, char *buf)
{
	ft_strdel(&pos->saved_ans);
	if (buf[0] != 10)
		pos->saved_ans = ft_strdup(pos->ans);
	if (hist && hist->next == NULL)
	{
		if (hist->cmd != NULL)
			ft_strdel(&hist->cmd);
		hist->cmd = ft_strdup(pos->ans);
	}
	if (pos->ans[0] == '\0' || (pos->is_complete == 0 && pos->let_nb > 0 && pos->ans[pos->let_nb - 1] == '\n' && pos->act_co == pos->len_prompt))
		pos->history_mode = 0;
}

t_hist		*check_input(char *buf, t_pos *pos, t_hist *hist, t_inter *inter)
{
	(void)inter;
	if (buf[0] == 27)
		hist = escape_code(buf, pos, hist);
	else
	{
		ft_bzero(buf + 1, 3);
		if (buf[0] == 127 && pos->let_nb > 0)
			input_is_backspace(pos);
		else if (buf[0] == 10)
			hist = input_is_entry(pos, hist, buf);
		else if (buf[0] != 127 && buf[0] != 10)
			input_is_printable_char(pos, buf);
		update_history(pos, hist, buf);
	}
	if (buf[0] != 10 && pos->ans_printed == 0)
	{
		clean_screen(pos);
		print_ans_start(pos, buf);
	}
	pos->ans_printed = 0;
	return (hist);
}
