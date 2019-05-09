/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   copy.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 14:22:14 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 10:29:27 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void		print_from_begin(t_pos *pos)
{
	clean_at_start(pos);
	print_ans(pos, 0, pos->start_co);
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

void	display_line(t_pos *pos)
{
	int		len;

	len = 0;
	if (pos->start_select == -1)
		return ;
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	if (pos->let_nb_saved == 0)
	{
		clean_at_start(pos);
		print_ans(pos, 0, pos->start_co);
	}
	else
	{
		len = go_to_let_nb_saved(pos);
		pos->debug = pos->start_li + len / pos->max_co;
		tputs(tgoto(tgetstr("cm", NULL), len % pos->max_co, pos->start_li + len / pos->max_co), 1, ft_putchar);
		tputs(tgetstr("cd", NULL), 1, ft_putchar);
		print_ans(pos, pos->let_nb_saved, len % pos->max_co);
	}
	tputs(tgetstr("me", NULL), 1, ft_putchar);
}

static void		select_left(t_pos *pos)
{
	if (pos->let_nb == 0)
		return ;
	if (pos->start_select == -1)
		pos->start_select = pos->let_nb;
	left_arrow(pos);
}

static void		select_right(t_pos *pos)
{
	if (pos->let_nb >= (int)ft_strlen(pos->ans))
		return ;
	if (pos->start_select == -1)
		pos->start_select = pos->let_nb;
	right_arrow(pos);
}

int		is_select(char *buf, t_pos *pos)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59)
		return (1);
	pos->start_select = -1;
	return (0);
}

void	selected(t_pos *pos, char *buf)
{
	if (buf[5] == 67)
		select_right(pos);
	else if (buf[5] == 68)
		select_left(pos);
	display_line(pos);
	pos->ans_printed = 1;
}

void	selection_check(t_pos *pos, char *buf)
{
	if (pos->ans[0] == '\0')
		return ;
	if (pos->start_select != -1 && is_select(buf, pos) == 0)
		print_from_begin(pos);
	if (is_select(buf, pos) == 1)
		selected(pos, buf);
	else
	pos->start_select = -1;
}
