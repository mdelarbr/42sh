/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 15:46:10 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 09:22:34 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int			get_len_with_lines(t_pos *pos)
{
	int		i;
	int		len;

	i = -1;
	len = pos->len_prompt;
	while (pos->ans[++i])
	{
		if (pos->ans[i] != '\n')
			len += 1;
		if (pos->ans[i] == '\n')
		{
			len += pos->max_co - (len % pos->max_co);
			if (pos->is_complete == 0 || pos->was_incomplete == 1)
				len += pos->len_prompt;
		}
	}
	return (len);
}

int			go_to_let_nb_saved(t_pos *pos)
{
	int		i;
	int		len;

	i = -1;
	len = pos->len_prompt;
	while (++i < pos->let_nb_saved)
	{
		if (pos->ans[i] != '\n')
			len += 1;
		if (pos->ans[i] == '\n')
		{
			len += pos->max_co - (len % pos->max_co);
			if (pos->is_complete == 0)
				len += pos->len_prompt;
		}
	}
	return (len);
}

int			len_of_previous_line(t_pos *pos)
{
	int		len;
	int		i;

	pos->debug5 += 10;
	i = pos->let_nb - 2;
	len = 0;
	while (i >= 0 && pos->ans[i] != '\n')
	{
		i--;
		len++;
	}
	if (pos->act_li == pos->start_li || pos->is_complete == 0 || i == -1)
	{
		len += pos->len_prompt;
	}
	if (len > pos->max_co)
		len = len % pos->max_co;
	return (len);
}

int			count_nb_line(t_pos *pos, int *j)
{
	int		nb_line;
	int		i;

	nb_line = 0;
	i = 0;
	*j = pos->len_prompt;
	while (pos->ans[i])
	{
		if (pos->ans[i] == '\n')
		{
			nb_line += 1;
			*j = pos->len_prompt;
		}
		else if (*j % pos->max_co == 0 && *j != 0)
			nb_line += 1;
		++*j;
		i++;
	}
	--*j;
	return (nb_line);
}

int			go_to_let_nb(t_pos *pos)
{
	int	i;
	int	len;

	i = -1;
	len = pos->len_prompt;
	while (++i < pos->let_nb)
	{
		if (pos->ans[i] != '\n')
			len += 1;
		if (pos->ans[i] == '\n')
		{
			len += pos->max_co - (len % pos->max_co);
			if (pos->is_complete == 0 || pos->was_incomplete == 1)
				len += pos->len_prompt;
		}
	}
	return (len);
}