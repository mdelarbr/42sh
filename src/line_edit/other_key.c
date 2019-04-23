/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   other_key.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:09:50 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 07:53:18 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
void	new_boucle(t_all *all)
{
	long key;

	key = 0;
	while (1)
	{
		ft_putstr("\n>");
		while (read(0, &key, 8) > -1)
		{
			if (key == ENTER)
			{
				check_quote(all);
				return ;
			}
			all->last->cmd = check_char(all->last->cmd, key, all);
			display(all->last->cmd, all);
		}
	}
}

int		check_count(t_all *all)
{
	if (all->count.quote % 2 != 0)
		return (-1);
	else if (all->count.dquote % 2 != 0)
		return (-1);
	else if (all->count.subsh > 0)
		return (-1);
	else if (all->count.cursh > 0)
		return (-1);
	return (0);
}

int		check_quote(t_all *all)
{
	int i;

	i = 0;
	while (all->last->cmd[i])
	{
		if (all->last->cmd[i] == '\'' && all->last->cmd[i - 1] != '\\')
			all->count.quote++;
		if (all->last->cmd[i] == '\"' && all->last->cmd[i - 1] != '\\')
			all->count.dquote++;
		if (all->last->cmd[i] == '(' && all->last->cmd[i - 1] != '\\')
			all->count.subsh++;
		if (all->last->cmd[i] == '{' && all->last->cmd[i - 1] != '\\')
			all->count.cursh++;
		if (all->last->cmd[i] == ')' && all->last->cmd[i - 1] != '\\')
			all->count.subsh--;
		if (all->last->cmd[i] == '}' && all->last->cmd[i - 1] != '\\')
			all->count.cursh--;
	}
	if (check_count(all) == -1)
		new_boucle(all);
	return (0);
}*/

void	do_the_enter(t_all **all)
{
	tputs(tgetstr("dl", NULL), 1, ft_put_c);
	tputs(tgoto(tgetstr("cm", NULL), 0, (*all)->wind.srt_line), 1, ft_put_c);
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

void	jump_right(t_all **all)
{
	int i;
	int len;

	len = ft_strlen((*all)->last->cmd);
	i = (*all)->wind.pos_col - 1;
	printf("--%d|", i);
	if (i == ft_strlen((*all)->last->cmd) || len == 0 || len <= i)
	{
		(*all)->wind.pos_col = len;
		return ;
	}
	if (is_space((*all)->last->cmd[i]) == 1)
	{
		while ((*all)->last->cmd[i] && i < len &&
					(is_space((*all)->last->cmd[i]) == 1))
			i++;
	}
	else
	{
		while ((*all)->last->cmd[i] && i < len &&
					(is_space((*all)->last->cmd[i]) == 0))
			i++;
		while ((*all)->last->cmd[i] && i < len &&
					(is_space((*all)->last->cmd[i]) == 1))
			i++;
	}
	printf("--%d|\n", i);
	(*all)->wind.pos_col = i;
}

void	jump_left(t_all **all)
{
	int i;

	i = (*all)->wind.pos_col - 1;
	printf("--%d|\n", i);
	if (i == 1 || i <= 0)
	{
		(*all)->wind.pos_col = -1;
		return ;
	}
	if (is_space((*all)->last->cmd[i]) == 1)
	{
		while ((*all)->last->cmd[i] && i > 0 &&
					(is_space((*all)->last->cmd[i]) == 1))
			i--;
		while ((*all)->last->cmd[i] && i > 0 &&
					(is_space((*all)->last->cmd[i]) == 0))
			i--;
	}
	else
	{
		while ((*all)->last->cmd[i] && i > 0 &&
					(is_space((*all)->last->cmd[i]) == 0))
			i--;
		while ((*all)->last->cmd[i] && i > 0 &&
					(is_space((*all)->last->cmd[i]) == 1))
			i--;
		while ((*all)->last->cmd[i] && i > 0 &&
					(is_space((*all)->last->cmd[i]) == 0))
			i--;
	}
	if (i == 1 || i == 0)
		(*all)->wind.pos_col = 0;
	else
		(*all)->wind.pos_col = i + 1;
	printf("--%d|\n", i);
}
