/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alias.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 16:36:57 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 12:08:07 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"

void	write_alias(t_ft *ft)
{
	char	*str;
	t_var	*save;

	ft->fd_alias = open(ALIAS, O_WRONLY | O_TRUNC);
	save = ft->env;
	while (save)
	{
		if (save->type == ALIAS_VAR)
		{
			str = ft_strjoin(save->var, "=");
			ft_strjoin_free(&str, save->val);
			ft_strjoin_free(&str, "\n");
			write(ft->fd_alias, str, ft_strlen(str));
			ft_strdel(&str);
		}
		save = save->next;
	}
	close(ft->fd_alias);
	ft->fd_alias = -1;
}

void	read_alias(t_ft *ft)
{
	char	*str;
	char	**tab;
	t_var	*new;

	ft->fd_alias = open(ALIAS, O_RDONLY);
	str = NULL;
	while (get_next_line(ft->fd_alias, &str))
	{
		tab = ft_strsplit(str, '=');
		new = create_var_str_elem(tab[0], tab[1]);
		new->type = ALIAS_VAR;
		ft_add_var_elem(&(ft->env), new);
		ft_free_tab(tab);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	close(ft->fd_alias);
	ft->fd_alias = -1;
}

void	get_alias(t_ft *ft)
{
	if (ft_file_exists(ALIAS))
	{
		if (ft_file_rrights(ALIAS))
			read_alias(ft);
		else
			ft_error(3);
	}
	else
	{
		if (ft_create_file(ALIAS))
			ft_error(-3);
		else
			ft_error(3);
	}
}

void	save_alias(t_ft *ft)
{
	if (ft_file_exists(ALIAS))
	{
		if (ft_file_wrights(ALIAS))
			write_alias(ft);
		else
			ft_error(-6);
	}
	else
	{
		if (ft_create_file(ALIAS))
		{
			ft_error(-3);
			write_alias(ft);
		}
		else
			ft_error(-6);
	}
}
