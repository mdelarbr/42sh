/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_through_history.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 07:42:17 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/02 08:54:16 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static t_hist	*stay_down_in_history(t_hist *hist, t_pos *pos)
{
	if (hist->cmd)
	{
		if (pos->is_complete == 0)
		{
			pos->ans[pos->let_nb_saved] = '\0';
			pos->act_co = pos->len_prompt;
		}
		else
		{
			free(pos->ans);
			pos->ans = ft_strdup(hist->cmd);
		}
	}
	else
	{
		pos->act_li = pos->start_li;
		pos->act_co = pos->start_co;
		pos->let_nb = 0;
	}
	pos->history_loop = 0;
	return (hist);
}

static t_hist	*go_back_down_in_history(t_hist *hist, t_pos *pos)
{
	hist = hist->next;
	if (hist->cmd != NULL && pos->is_complete == 1)
	{
		free(pos->ans);
		pos->ans = ft_strdup(hist->cmd);
	}
	else if (pos->is_complete == 0)
	{
		pos->ans[pos->let_nb_saved] = '\0';
		pos->ans = ft_strjoinf(pos->ans, hist->cmd, 1);
		if (hist->cmd == NULL)
			pos->history_loop += 1;
	}
	else
	{
		free(pos->ans);
		pos->ans = ft_strnew(0);
	}
	return (hist);
}

static t_hist	*go_back_in_history(t_hist *hist, t_pos *pos)
{
	if (hist->prev == NULL && hist->cmd == NULL)
		return (hist);
	if (hist && hist->prev != NULL)
		hist = hist->prev;
	if (hist && hist->next != NULL && hist->next->cmd != NULL &&
			pos->is_complete == 0 && pos->history_loop++ == 0)
		hist = hist->next;
	if (pos->is_complete == 0)
	{
		if ((int)ft_strlen(pos->ans) > pos->let_nb_saved)
			pos->ans[pos->let_nb_saved] = '\0';
		pos->ans = ft_strjoinf(pos->ans, hist->cmd, 1);
	}
	else if (pos->is_complete == 1)
	{
		free(pos->ans);
		pos->ans = ft_strdup(hist->cmd);
	}
	return (hist);
}

t_hist			*move_through_history(t_hist *hist, t_pos *pos, char *usage)
{
	if (pos->history_mode == 1 && ft_strcmp(usage, "up") == 0)
		hist = search_up_complete_in_history(hist, pos);
	else if (pos->history_mode == 1 && ft_strcmp(usage, "down") == 0)
		hist = search_down_complete_in_history(hist, pos);
	else if (ft_strcmp(usage, "up") == 0 && hist && hist->prev)
		hist = go_back_in_history(hist, pos);
	else if (ft_strcmp(usage, "down") == 0 && hist && hist->next)
		hist = go_back_down_in_history(hist, pos);
	else if (ft_strcmp(usage, "down") == 0)
		hist = stay_down_in_history(hist, pos);
	update_position(pos);
	return (hist);
}
