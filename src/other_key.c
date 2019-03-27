/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other_key.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:09:50 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 10:11:37 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	do_back(t_all *all)
{
	(void)all;
	ft_putstr("BACK");
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
