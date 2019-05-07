/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_key.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 10:24:34 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/06 12:23:47 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void		scan_pos_ans(t_pos *pos)
{
	if (pos->let_nb == 0)
		return ;
	ft_putchar(pos->ans[pos->let_nb - 1]);
	while (pos->let_nb > 0)
		;
}

void		input_is_tab(t_pos *pos)
{
	int		usage;

	usage = 1;
	scan_pos_ans(pos);
	(void)pos;
	pos->ans_printed = 1;
	return ;
}
