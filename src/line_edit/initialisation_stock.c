/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initialisation_stock.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 08:12:35 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 13:32:42 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void			init_terminfo(t_pos *pos)
{
	tcgetattr(0, &(pos->my_term));
	tcgetattr(0, &(pos->old_term));
	pos->my_term.c_lflag &= ~(ICANON);
	pos->my_term.c_lflag &= ~(ECHO);
	pos->my_term.c_cc[VMIN] = 1;
	pos->my_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &(pos->my_term));
}

static void		get_start_info(char *buf, t_pos *pos)
{
	int			i;

	i = 0;
	while (buf[i] && buf[i] != '[')
		i++;
	if (buf[i] == '\0')
		pos->start_li = -1;
	else
	{
		pos->start_li = ft_atoi(buf + i + 1) - 1 +
			ft_strlen(pos->prompt) / pos->max_co;
		if (pos->start_li > pos->max_li)
			pos->start_li = pos->max_li;
	}
	i = 0;
	while (buf[i] && buf[i] != ';')
		i++;
	if (buf[i] == '\0')
		pos->start_co = -1;
	else
		pos->start_co = ft_atoi(buf + i + 1) - 1 + pos->len_prompt;
}

void			*stock(void *to_stock, int usage)
{
	static t_pos	*stock_pos;
	static char		*copy;

	if (usage == 0)
		stock_pos = to_stock;
	else if (usage == 1)
		return (stock_pos);
	else if (usage == 3)
		copy = to_stock;
	else  if (usage == 4)
		return (copy);
	else if (usage == 5 && copy)
		ft_strdel(&copy);
	return (NULL);
}

static void		init_classic_var(t_pos *pos)
{
	pos->history_mode = 0;
	pos->ans_printed = 0;
	pos->let_nb = 0;
	pos->let_nb_saved = 0;
	pos->history_loop = 0;
	pos->was_incomplete = 0;
	pos->start_select = -1;
	pos->debug = 0;
	pos->debug2 = 0;
	pos->debug3 = 0;
	pos->debug4 = 0;
	pos->debug5 = 0;
	pos->debugchar = NULL;
}

void			init_pos(t_pos *pos)
{
	char		buf[10];

	ft_bzero(buf, 9);
	pos->max_co = tgetnum("co");
	pos->max_li = tgetnum("li") - 1;
	if (ft_strlen(pos->prompt) == 2)
		pos->len_prompt = 2;
	else
		pos->len_prompt = ft_strlen(pos->prompt) % pos->max_co;
	pos->ans = ft_strnew(0);
	pos->saved_ans = NULL;
	pos->len_ans = pos->len_prompt;
	init_classic_var(pos);
	write(1, "\033[6n", 4);
	read(1, buf, 8);
	get_start_info(buf + 1, pos);
	if (pos->start_li == -1 || pos->start_co == -1)
	{
		pos->start_li = 0;
		pos->start_co = pos->len_prompt;
		tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
		print_prompt(pos);
	}
	pos->act_li = pos->start_li;
	pos->act_co = pos->start_co;
	stock(pos, 0);
}
