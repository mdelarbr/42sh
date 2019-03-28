/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arrow.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 16:35:58 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 08:49:53 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	do_up(t_all *all, char **res)
{
	if (res && all->history->next == NULL)
	{
		all->last->next = malloc(sizeof(t_history));
		all->last->next->prev = all->last;
		all->last = all->last->next;
		all->last->cmd = ft_strdup(*res);
		all->last->next = NULL;
	}
	if (all->history->prev != NULL)
	{
//		if (res)
//			ft_strdel(res);
		(*res) = ft_strdup(all->history->cmd);
		all->history = all->history->prev;
	}
}

void	do_down(t_all *all)
{
	(void)all;
	ft_putstr("DOWN");
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
