/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   start_termcaps.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:44:25 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 10:24:40 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void		print_prompt(t_pos *pos)
{
	ft_putcolor(BYELLOW, pos->prompt, RESET);
}

static int	start_termcaps(t_pos *pos, char *buf, char *prompt)
{
	int		ret;

	if (pos->prompt == NULL)
		pos->prompt = ft_strdup(prompt);
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

char		*termcaps42sh(char *prompt, t_pos *pos, t_hist *hist)
{
	int				ret;
	unsigned char	buf[9];

	while (hist->next)
		hist = hist->next;
	start_termcaps(pos, (char*)buf, prompt);
	print_prompt(pos);
	signal_list();
	while (1)
	{
		ret = read(0, buf, 1);
		if (buf[0] == 137)
			return (NULL);
		if (buf[0] == 27)
			ret = read(0, buf + 1, 8);
		if (pos->max_co > 2)
			hist = check_input(buf, pos, hist);
		print_info(pos);
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
