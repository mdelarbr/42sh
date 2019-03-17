/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 16:41:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:51:33 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

void	read_history(t_ft *ft)
{
	{
		char *str;
		char **tab;
		t_list	*new;

		ft->fd_his = open(HISTORY, O_RDONLY);
		while (get_next_line(ft->fd_his, &str))
		{
			new = create_list_elem(str);
			ft_add_list_elem(&(ft->his), new);
			ft_strdel(&str);
		}
		ft_strdel(&str);
		close(ft->fd_his);
		ft->fd_his = -1;
	}
}

void	get_history(t_ft *ft)
{
	if (ft_file_exists(HISTORY))
	{
		if (ft_file_rrights(HISTORY))
			read_history(ft);
		else
			ft_error(2);
	}
	else
	{
		if (ft_create_file(HISTORY))
			ft_error(-2);
		else
			ft_error(2);
	}
}

void	write_history(t_ft *ft)
{
	char	*str;
	t_list	*save;

	ft->fd_his = open(HISTORY, O_WRONLY | O_TRUNC);
	save = ft->his;
	while (save)
	{
		str = ft_strjoin(save->content, "\n");
		write(ft->fd_his, str, ft_strlen(str));
		save = save->next;
		ft_strdel(&str);
	}
	close(ft->fd_his);
	ft->fd_his = -1;
}

void	save_history(t_ft *ft)
{
	if (ft_file_exists(HISTORY))
	{
		if (ft_file_wrights(HISTORY))
			write_history(ft);
		else
			ft_error(-7);
	}
	else
	{
		if (ft_create_file(HISTORY))
		{
			ft_error(-2);
			write_history(ft);
		}
		else
			ft_error(-7);
	}
}
