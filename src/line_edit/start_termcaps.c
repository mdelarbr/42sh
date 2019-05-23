/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   start_termcaps.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:44:25 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 10:40:11 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void		print_prompt(t_pos *pos)
{
	ft_printf("{B.T.cyan.}%s{eoc}", pos->prompt);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
}

static int	start_termcaps(t_pos *pos, char *buf)
{
	int		ret;

	if (pos->prompt == NULL)
		pos->prompt = ft_strdup("$ ");
	init_terminfo(pos);
	ret = check_term();
	if (ret == -1)
		exit(0);
	init_pos(pos);
	ft_bzero(buf, 8);
	return (ret);
}

		//		print_info(pos);
		//		print_hist(pos, hist);

char		*termcaps42sh(t_pos *pos, t_hist *hist)
{
	int				ret;
	unsigned char	buf[9];

	while (hist->next)
		hist = hist->next;
	ghist = &hist;
	start_termcaps(pos, (char*)buf);
	print_prompt(pos);
	signal_list();
//	print_info(pos);
//	print_hist(pos, hist);
	while (1)
	{
		ret = read(0, buf, 1);
		if (buf[0] == 137)
			return (NULL);
		if (buf[0] == 27 || buf[0] == 226 || buf[0] == 195)
			ret = read(0, buf + 1, 8);
		if (pos->max_co > 2)
			hist = check_input(buf, pos, hist);
//		print_info(pos);
//		print_hist(pos, hist);
		if (buf[0] == 10 && pos->is_complete == 1)
		{
			tputs(tgoto(tgetstr("cm", NULL),
				pos->act_co, pos->act_li), 1, ft_putchar);
			write(1, "\n", 1);
			return (pos->ans);
		}
		ft_bzero(buf, 8);
	}
	return (NULL);
}
