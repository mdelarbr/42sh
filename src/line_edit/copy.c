/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   copy.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/03 10:06:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/06 13:10:59 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static void	clean_at_start(t_pos *pos)
{
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL),
		pos->start_co, pos->start_li), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL),
		pos->start_co, pos->start_li), 1, ft_putchar);
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
}

void		display_line(t_pos *pos)
{
	if (pos->start_select == -1)
		return ;
	clean_at_start(pos);
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	if (pos->start_select > pos->let_nb)
	{
		write(1, pos->ans, pos->let_nb);
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
		write(1, pos->ans + pos->let_nb, pos->start_select - pos->let_nb);
		tputs(tgetstr("me", NULL), 1, ft_putchar);
		write(1, pos->ans + pos->start_select, pos->len_ans - pos->start_select);
	}
	else
	{
		write(1, pos->ans, pos->start_select);
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
		write(1, pos->ans + pos->start_select, pos->let_nb - pos->start_select);
		tputs(tgetstr("me", NULL), 1, ft_putchar);
		write(1, pos->ans + pos->let_nb, pos->len_ans - pos->let_nb );
	}
}

static void	select_left(t_pos *pos)
{
	if (pos->let_nb == 0)
		return ;
	if (pos->start_select == -1)
		pos->start_select = pos->let_nb;
	left_arrow(pos);
}

static void	select_right(t_pos *pos)
{
	if (pos->let_nb >= pos->len_ans)
		return ;
	if (pos->start_select == -1)
		pos->start_select = pos->let_nb;
	right_arrow(pos);
}

int			is_select(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59)
		return (1);
	return (0);
}

void		selected(t_pos *pos, char *buf)
{
	if (buf[5] == 67)
		select_right(pos);
	else if (buf[5] == 68)
		select_left(pos);
	pos->ans_printed = 1;
	display_line(pos);
}