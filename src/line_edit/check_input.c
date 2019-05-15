/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 14:41:17 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 09:51:39 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static void		update_history(t_pos *pos, t_hist *hist, char *buf)
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
	if (pos->ans[0] == '\0' || (pos->is_complete == 0 && pos->let_nb > 0 &&
				pos->ans[pos->let_nb - 1] == '\n' && pos->act_co == pos->len_prompt))
		pos->history_mode = 0;
}

t_hist			*check_input(unsigned char *buf, t_pos *pos, t_hist *hist)
{
	if (buf[0] != 226 && buf[0] != 195)
		selection_check(pos, (char*)buf);
	if (buf[0] == 27)
		hist = escape_code((char*)buf, pos, hist);
	else if (buf[0] == 226 || buf[0] == 195)
		check_copy(buf, pos);
	else
	{
		if (buf[0] == 9)
			input_is_tab(pos);
		else if (buf[0] == 127)
			pos->ans_printed = input_is_backspace(pos);
		else if (buf[0] == 10)
			hist = input_is_entry(pos, hist, (char*)buf);
		else if (buf[0] != 127 && buf[0] != 10)
			input_is_printable_char(pos, (char*)buf);
		update_history(pos, hist, (char*)buf);
	}
	if (buf[0] != 10 && pos->ans_printed == 0)
		prepare_to_print(pos, (char*)buf);
	pos->ans_printed = 0;
	return (hist);
}
