/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initialisation_stock.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 09:57:21 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 10:37:27 by rlegendr    ###    #+. /#+    ###.fr     */
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

void			get_cursor_info(t_pos *pos, int *li, int *co)
{
	int			i;
	char		*buf;

	buf = malloc(10);
	ft_bzero(buf, 9);
	i = 0;
	write(1, "\033[6n", 5);
	read(1, buf, 8);
	buf = buf + 1;
	while (buf[i] && buf[i] != '[')
		i++;
	if (buf[i] == '\0')
		*li = -1;
	else
	{
		*li = ft_atoi(buf + i + 1) - 1 +
			ft_strlen(pos->prompt) / pos->max_co;
		if (*li > pos->max_li)
			*li = pos->max_li;
	}
	i = 0;
	while (buf[i] && buf[i] != ';')
		i++;
	if (buf[i] == '\0')
		*co = -1;
	else
		*co = ft_atoi(buf + i + 1) - 1 + pos->len_prompt;
	free(buf - 1);
}

void			*stock(void *to_stock, int usage)
{
	static t_pos	*stock_pos = NULL;
	static char		*stock_copy = NULL;
	static t_var	*stock_var = NULL;
	static t_hist	*stock_hist = NULL;

	if (usage == 0)
		stock_pos = to_stock;
	else if (usage == 1)
		return (stock_pos);
	else if (usage == 3)
		stock_copy = to_stock;
	else if (usage == 4)
		return (stock_copy);
	else if (usage == 5)
		stock_var = to_stock;
	else if (usage == 6)
		return (stock_var);
	else if (usage == 7)
		stock_hist = to_stock;
	else if (usage == 8)
		return (stock_hist);
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
//	pos->navigation = 0;
	pos->ctrl_hist_cmd = ft_strnew(0);
	pos->debug = 0;
	pos->debug2 = 0;
	pos->debug3 = 0;
	pos->debug4 = 0;
	pos->debug5 = 0;
	pos->error = 0;
	pos->ctrl_search_history = 0;
	pos->debugchar = NULL;
	pos->debugchar2 = NULL;
}

void			init_pos(t_pos *pos)
{
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

	get_cursor_info(pos, &pos->start_li, &pos->start_co);
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
