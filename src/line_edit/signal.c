/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signal.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 08:09:42 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 10:13:13 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static void		resize_screen(t_pos *pos)
{
	int		len;

	check_term();
	pos->max_co = tgetnum("co");
	pos->max_li = tgetnum("li") - 1;
	len = get_len_with_lines(pos);
	pos->let_nb = ft_strlen(pos->ans);
	pos->len_ans = pos->let_nb;
	short_update(pos, len);
	clean_at_start(pos);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	tputs(tgoto(tgetstr("cm", NULL), 0, pos->start_li), 1, ft_putchar);
	print_prompt(pos);
	print_ans(pos, 0, pos->start_co);
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
	print_info(pos);
}

static void		ctrl_c(t_pos *pos)
{
	write(1, "\n", 1);
	free(pos->ans);
	init_pos(pos);
	print_prompt(pos);
}

static void		sighandler(int signum)
{
	t_pos *pos;

	pos = stock(NULL, 1);
	if (signum == RESIZING)
		resize_screen(pos);
	if (signum == CTRL_C)
		ctrl_c(pos);
	pos->debug = signum;
	print_info(pos);
}

void			signal_list(void)
{
	signal(SIGWINCH, sighandler);
	signal(SIGINT, sighandler);
}
