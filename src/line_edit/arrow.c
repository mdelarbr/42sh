/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arrow.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 16:35:58 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 11:01:41 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"
/*
void	do_up(t_all *all, char **res)
{
	if (all->last && all->history)
	{
		ft_strdel(res);
		*res = ft_strdup(all->history->cmd);
		if (all->history->prev)
			all->history = all->history->prev;
	}
}

void	do_down(t_all *all, char **res)
{
	if (ft_strcmp((*res), all->tmp) == 0)
		return ;
	if ((*res) && all->history->next == NULL)
	{
		ft_strdel(res);
		(*res) = ft_strdup(all->tmp);
	}
	if (all->history && all->history->next)
	{
		all->history = all->history->next;
		ft_strdel(res);
		(*res) = ft_strdup(all->history->cmd);
	}
}
*/
void	do_up(t_all *all)
{
	if (all->last && all->last->prev != NULL)
		all->last = all->last->prev;
}

void	do_down(t_all *all)
{
	if (all->last && all->last->next != NULL)
		all->last = all->last->next;
}

void	do_left(t_all *all)
{
	(void)all;
	ft_putstr("LEFT");
}

void	do_right(t_all *all)
{
	(void)all;
	ft_putstr("RIGHT");
}
