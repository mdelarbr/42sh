/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   jump.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/25 08:12:14 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/03 08:27:14 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void		short_update(t_pos *pos, int len)
{
	pos->act_li = pos->start_li + len / pos->max_co;
	pos->act_co = len % pos->max_co;
	while (pos->act_li > pos->max_li)
	{
		pos->act_li -= 1;
		prompt_is_on_last_char(pos);
	}
}

int			go_to_let_nb(t_pos *pos)
{
	int		i;
	int		len;

	i = -1;
	len = pos->len_prompt;
	while (++i < pos->let_nb)
	{
		if (pos->ans[i] != '\n')
			len += 1;
		if (pos->ans[i] == '\n')
		{
			len += pos->max_co - (len % pos->max_co);
			if (pos->is_complete == 0 || pos->was_incomplete == 1)
				len += pos->len_prompt;
		}
	}
	return (len);
}

void		jump_left(t_pos *pos)
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
			left_arrow(NULL, pos);
	while (pos->let_nb > 0 && ft_isspace(pos->ans[pos->let_nb - 1]) == 0)
		pos->let_nb -= 1;
	int len = go_to_let_nb(pos);
	short_update(pos, len);
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

void		jump_right(t_pos *pos)
{
	if (pos->let_nb >= pos->len_ans)
		return ;
	if (pos->is_complete == 0 && pos->ans && pos->let_nb > 0 && pos->ans[pos->let_nb] == '\n')
		return ;
	if (pos->ans[pos->let_nb] && ft_isspace(pos->ans[pos->let_nb]) == 0)
	{
		while (pos->ans[pos->let_nb] && ft_isspace(pos->ans[pos->let_nb]) == 0)
			right_arrow(NULL, pos);
	}
	while (pos->ans[pos->let_nb] && ft_isspace(pos->ans[pos->let_nb]) == 1)
		right_arrow(NULL, pos);
}

void		go_hard(t_pos *pos)
{
	while (pos->ans[pos->let_nb] && pos->ans[pos->let_nb] != '\n')
	{
		pos->let_nb++;
		if (pos->act_co == pos->max_co - 1)
		{
			pos->act_co = 0;
			pos->act_li++;
		}
		else
			pos->act_co++;
	}
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

void		or_go_home(t_pos *pos)
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
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li), 1, ft_putchar);
}

void		jump_UP(t_pos *pos)
{
	if (pos->is_complete == 0)
		return ;
}

void		jump_DOWN(t_pos *pos)
{
	if (pos->is_complete == 0)
		return ;
	
}

void		find_jump(char *buf, t_pos *pos)
{
	if (ft_strcmp(buf + 2, "[A") == 0)
		jump_UP(pos);
	if (ft_strcmp(buf + 2, "[B") == 0)
		jump_DOWN(pos);
	if (ft_strcmp(buf + 2, "[D") == 0)
		jump_left(pos);
	else if (ft_strcmp(buf + 2, "[C") == 0)
		jump_right(pos);
	else if (ft_strcmp(buf + 1, "[F") == 0)
		go_hard(pos);
	else if (ft_strcmp(buf + 1, "[H") == 0)
		or_go_home(pos);
}
