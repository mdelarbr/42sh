/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   jump.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 14:23:16 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 09:29:38 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void	jump_left(t_pos *pos)
{
	if (pos->is_complete == 0 && pos->act_co == 2)
		return ;
	if (pos->let_nb == 0)
		return ;
	if (ft_isspace(pos->ans[pos->let_nb]) == 0 && ft_isspace(pos->ans[pos->let_nb - 1]) == 1)
	{
		pos->let_nb--;
		pos->act_co--;
	}
	if (ft_isspace(pos->ans[pos->let_nb]) == 1)
		while (pos->let_nb > 0 && ft_isspace(pos->ans[pos->let_nb]) == 1)
			left_arrow(pos);
	while (pos->let_nb > 0 && ft_isspace(pos->ans[pos->let_nb - 1]) == 0)
		pos->let_nb -= 1;
//	int len = go_to_let_nb(pos);
	short_update(pos, go_to_let_nb(pos));
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

void	jump_right(t_pos *pos)
{
	if (pos->let_nb >= pos->len_ans)
		return ;
	if (pos->is_complete == 0 && pos->ans && pos->let_nb > 0 && pos->ans[pos->let_nb] == '\n')
		return ;
	if (pos->ans[pos->let_nb] && ft_isspace(pos->ans[pos->let_nb]) == 0)
	{
		while (pos->ans[pos->let_nb] && ft_isspace(pos->ans[pos->let_nb]) == 0)
			right_arrow(pos);
	}
	while (pos->ans[pos->let_nb] && ft_isspace(pos->ans[pos->let_nb]) == 1)
		right_arrow(pos);
}

void	go_hard(t_pos *pos)
{
/*	if (pos->is_complete == 0)
	{*/
		while (pos->ans[pos->let_nb])
		{
			if (pos->act_co == pos->max_co - 1 || pos->ans[pos->let_nb] == '\n')
			{
				pos->act_co = 0;
				pos->act_li++;
			}
			else
				pos->act_co++;
			pos->let_nb++;
		}
/*	}
	else
	{
		while (pos->ans[pos->let_nb] != '\0')
		{
			if (pos->ans[pos->let_nb + 1] == '\n')
			{
				pos->act_co = 0;
				pos->act_li++;
			}
			else
				pos->act_co++;
			pos->let_nb++;
		}
	}
*/	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

void	or_go_home(t_pos *pos)
{
	if (pos->is_complete == 0)
	{
		while (pos->let_nb > 0 && (pos->ans[pos->let_nb - 1] != '\n'))
		{
			pos->let_nb--;
			if (pos->act_co == 0)
			{
				pos->act_co = pos->max_co - 1;
				pos->act_li--;
			}
			else
				pos->act_co--;
		}
	}
	else
	{
		pos->act_co = pos->start_co;
		pos->act_li = pos->start_li;
		pos->let_nb = 0;
	}
/*
	while (pos->let_nb > 0 && (pos->ans[pos->let_nb - 1] != '\n'))
	{
		pos->let_nb--;
		if (pos->act_co == 0)
		{
			pos->act_co = pos->max_co - 1;
			pos->act_li--;
		}
		else
			pos->act_co--;
	}
*/	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

int		nb_line(t_pos *pos)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (pos->ans[i])
	{
		if (pos->ans[i] == '\n' || i % pos->max_co - 1 == 0)
			line++;
		i++;
	}
	return (line);
}

void	find_jump(char *buf, t_pos *pos)
{
	int	nb_line;

	pos->ans_printed = 1;
	nb_line = pos->start_li + get_len_with_lines(pos) / pos->max_co;
	if (ft_strcmp(buf + 2, "[A") == 0 && pos->act_li > pos->start_li)
		jump_up(pos);
	if (ft_strcmp(buf + 2, "[B") == 0 && nb_line > pos->act_li)
		jump_down(pos);
	if (ft_strcmp(buf + 2, "[D") == 0)
		jump_left(pos);
	else if (ft_strcmp(buf + 2, "[C") == 0)
		jump_right(pos);
	else if (ft_strcmp(buf + 1, "[F") == 0)
		go_hard(pos);
	else if (ft_strcmp(buf + 1, "[H") == 0)
		or_go_home(pos);
}
