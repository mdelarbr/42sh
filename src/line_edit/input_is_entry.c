/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_is_entry.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 07:21:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 13:41:50 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static t_hist	*entry_is_incomplete(t_pos *pos, t_hist *hist, char *buf)
{
	pos->act_co = pos->len_prompt;
	prepare_to_print(pos, buf);
	pos->let_nb_saved = ft_strlen(pos->ans);
	pos->was_incomplete = 1;
	return (hist);
}

static t_hist	*entry_is_complete(t_pos *pos, t_hist *hist)
{
	while (hist->next)
		hist = hist->next;
	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	if (ft_strlen(pos->ans) == 0)
		return (hist);
	if ((hist->prev && ft_strcmp(pos->ans, hist->prev->cmd) == 0))
	{
		hist->cmd = ft_secure_free(hist->cmd);
		return (hist->prev);
	}
	write(pos->history, pos->ans, ft_strlen(pos->ans));
	write(pos->history, "\n", 1);
	while (hist->next)
		hist = hist->next;
	if (hist->cmd)
		hist->cmd = ft_secure_free(hist->cmd);
	hist->cmd = ft_strdup(pos->ans);
	hist = add_list_back_hist(hist);
	hist = hist->prev;
	return (hist);
}

static void		check_expansion_and_token(t_pos *pos, t_hist *hist)
{
	t_tok		in;
	t_tokench	tok;

	check_history_expansion(pos, pos->ans, hist);
	pos->ctrl_hist_cmd = ft_secure_free(pos->ctrl_hist_cmd);
	init_tok(&in);
	check_token(pos, &in, &tok);
}

t_hist			*input_is_entry(t_pos *pos, t_hist *hist, char *buf)
{
	check_expansion_and_token(pos, hist);
	if (pos->ans == NULL)
	{
		ft_strdel(&pos->saved_ans);
		return (hist);
	}
	if (pos->is_complete == 0)
	{
		pos->history_mode = 0;
		input_is_printable_char(pos, buf);
	}
	short_update(pos, get_len_with_lines(pos));
	if (pos->is_complete == 0)
		entry_is_incomplete(pos, hist, buf);
	else
	{
		entry_is_complete(pos, hist);
		pos->was_incomplete = 0;
	}
	return (hist);
}
