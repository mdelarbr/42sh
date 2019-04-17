/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other_key.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:09:50 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 12:03:20 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	do_back(t_all *all, char **res)
{
	if (all->wind.pos_col > 0 && (*res))
	{
		(*res) = remove_char(res, all->wind.pos_col);
		all->wind.pos_col--;
	}
}

void	do_tab(t_all *all)
{
	(void)all;
	ft_putstr("TAB");
}

void	do_del(t_all *all)
{
	ft_putstr("DEL");
	(void)all;
}

void	do_the_enter(t_all **all)
{
	tputs(tgetstr("dl", NULL), 1, ft_put_c);
	tputs(tgoto(tgetstr("cm", NULL), 0, (*all)->wind.pos_line), 1, ft_put_c);
	ft_putcolor2(BRED, (*all)->prompt, RESET, (*all)->last->cmd);
	if ((*all)->last && (*all)->last->prev &&
				ft_strcmp((*all)->last->cmd, (*all)->last->prev->cmd) == 0)
	{
		ft_strdel(&(*all)->last->cmd);
		(*all)->last = (*all)->last->prev;
		free((*all)->last->next);
		(*all)->last->next = NULL;
		(*all)->history = (*all)->last;
	}
}