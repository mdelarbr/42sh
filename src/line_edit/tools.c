/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 08:15:39 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 11:21:47 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void	clean_at_start(t_pos *pos)
{
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL),
		pos->start_co, pos->start_li), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL),
		pos->start_co, pos->start_li), 1, ft_putchar);
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
}

void	short_update(t_pos *pos, int len)
{
	pos->act_li = pos->start_li + len / pos->max_co;
	pos->act_co = len % pos->max_co;
	while (pos->act_li > pos->max_li)
	{
		pos->act_li -= 1;
		prompt_is_on_last_char(pos);
	}
}

void	update_position(t_pos *pos)
{
	int		get_len;

	get_len = get_len_with_lines(pos);
	short_update(pos, get_len);
	pos->let_nb = ft_strlen(pos->ans);
	pos->len_ans = pos->let_nb;
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

int		is_in_selection_area(int i, t_pos *pos)
{
	if ((i >= pos->start_select && i <= pos->let_nb) ||
		(i <= pos->start_select && i >= pos->let_nb))
		return (1);
	return (0);
}

void	*to_stock(void *stock, int usage)
{
	static t_pos		*pos = NULL;
	static t_process	*p = NULL;
	static t_hist		*hist = NULL;
	static t_pid_launch	*spid = NULL;

	if (usage == 0)
		pos = stock;
	else if (usage == 1)
		return (pos);
	else if (usage == 2)
		p = stock;
	else if (usage == 3)
		return (p);
	else if (usage == 4)
		hist = stock;
	else if (usage == 5)
		return (hist);
	else if (usage == 6)
		spid = stock;
	else if (usage == 7)
		return (spid);
	return (NULL);
}
