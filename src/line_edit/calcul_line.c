/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 15:46:10 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 15:25:16 by rlegendr    ###    #+. /#+    ###.fr     */
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
			if (pos->is_complete == 0)
				len += pos->len_prompt;
		}
		pos->debug2 = len;
	}
	return (len);
}

/*
int			get_len_with_lines(t_pos *pos)
{
	int		i;
	int		len;
	int		line;

	line = pos->len_prompt;
	i = -1;
	len = pos->len_prompt;
	while (pos->ans[++i])
	{
		if (pos->ans[i] == '\n')
		{
			len += (pos->max_co - line % pos->max_co);
			if (pos->is_complete == 0)
			{
				line = pos->len_prompt;
			}
			else if (pos->is_complete == 1)
			{
				line = 0;
			}
		}
		else
		{
			line += 1;
			len += 1;
		}
	}
	return (len);
}
*/
int			len_of_previous_line(t_pos *pos)
{
	int		len;
	int		i;

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


