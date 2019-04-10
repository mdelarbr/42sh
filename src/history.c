/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 12:59:36 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 18:38:44 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

int		ft_file_wrights(char *path)
{
	if (access(path, W_OK) != -1)
		return (1);
	return (0);
}

int		ft_file_exists(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}

int		ft_execute(char *exec, char **opt, char **env)
{
	int		w;
	pid_t	p;

	p = fork();
	if (p == 0)
	{
		if (execve(exec, opt, env) == -1)
			return (0);
	}
	else
		wait(&w);
	return (1);
}

int		ft_create_file(char *path)
{
	char **s;

	s = malloc(sizeof(char *) * 3);
	if (access(path, F_OK) != 0)
	{
		if (access("/usr/bin/touch", X_OK) == 0)
		{
			s[0] = ft_strdup("/usr/bin/touch");
			s[1] = ft_strdup(path);
			s[2] = NULL;
			if (ft_execute("/usr/bin/touch", s, NULL))
			{
				ft_free_tab(s);
				return (1);
			}
			ft_free_tab(s);
			return (0);
		}
		ft_free_tab(s);
		return (0);
	}
	return (0);
}

t_history	*add_history(t_all *all)
{
	t_history	*new;

	new = malloc(sizeof(t_history));
	new->prev = all->last;
	new->next = NULL;
	new->cmd = ft_strdup("");
	return (new);
}

void	read_history(t_history **history)
{
	int			fd;
	char		*str;
	t_history	*prev;
	t_history	*save;

	str = NULL;
	fd = open(HIST, O_RDONLY);
	(*history) = malloc(sizeof(t_history));
	save = (*history);
	prev = (*history);
	(*history)->next = NULL;
	(*history)->prev = NULL;
	(*history)->cmd = NULL;
	while (get_next_line(fd, &str))
	{
		prev = (*history);
		if ((*history)->cmd != NULL)
		{
			(*history)->next = malloc(sizeof(t_history));
			(*history) = (*history)->next;
			(*history)->prev = prev;
		}
		(*history)->cmd = ft_strdup(str);
		(*history)->len = ft_strlen(str);
		printf("hist = %s\n", (*history)->cmd);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	(*history)->next = NULL;
	(*history) = save;
}

void	get_history(t_history **history)
{
	if (ft_file_exists(HIST))
	{
		if (ft_file_wrights(HIST))
			read_history(history);
		else
			ft_error(2);
	}
	else
	{
		ft_create_file(HIST);
	}
}

void	write_history(t_all *all)
{
	char		*str;
	int			fd;

	fd = open(HIST, O_WRONLY | O_TRUNC);
	while (all->last->prev)
		all->last = all->last->prev;
	while (all->last)
	{
		str = ft_strjoin(all->last->cmd, "\n");
		write(fd, str, ft_strlen(str));
		all->last = all->last->next;
		ft_strdel(&str);
	}
	close(fd);
	fd= -1;
}
