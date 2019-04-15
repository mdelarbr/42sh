/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 15:56:20 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 11:01:41 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	free_env(t_env *var)
{
	t_env *tmp;

	tmp = var;
	while (var)
	{
		ft_strdel(&var->name);
		ft_strdel(&var->data);
		var = var->next;
		free(tmp);
		tmp = var;
	}
}

void	free_all(t_all *all)
{
	t_history	*save;

	free_env(all->env);
	while (all->history && all->history->prev)
		all->history = all->history->prev;
	while (all->history && all->history->next)
	{
		save = all->history;
		free(all->history->cmd);
		all->history = all->history->next;
		free(save);
	}
	free(all->history);
	free(all);
}
