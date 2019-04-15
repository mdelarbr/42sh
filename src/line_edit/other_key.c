/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other_key.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:09:50 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 11:01:41 by mjalenqu    ###    #+. /#+    ###.fr     */
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
