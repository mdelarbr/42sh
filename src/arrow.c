/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arrow.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 16:35:58 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 13:27:18 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	do_up(t_all *all, char **res)
{
	if (all->up == 0)
		all->tmp = ft_strdup(*res);
	all->up++;
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
