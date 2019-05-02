/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_main.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 11:29:02 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 11:10:31 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"

int			use_execve(char **res, t_var *l_var)
{
	char	**path;
	char	*tmp;
	int		i;
	t_var	*start;

	start = l_var;
	while (start->next && ft_strcmp(start->name, "PATH") != 0)
		start = start->next;
	if (!(start))
		return (-1);
	path = ft_strsplit(start->data, ':');
	i = 0;
	while (path[i])
	{
		tmp = strjoin_path(path[i], res[0]);
		if (use_execve_acces(tmp, res, l_var) == 0)
			return (0);
		i++;
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp);
	return (-1);
}

int			exec_path(char **res, t_var *var)
{
	int		ret;

	ret = 0;
	if (access(res[0], F_OK) == 0)
	{
		ret = 1;
		solve_execve(res[0], res, var);
	}
	return (ret);
}

int			solve_execve(char *path, char **arg, t_var *var)
{
	char	**array;
	pid_t	pid;

	pid = fork();
	array = split_env(var);
	if (pid == 0)
	{
		if (execve(path, arg, array) == -1)
			return (-1);
	}
	else
		wait(&pid);
	return (1);
}

void		main_exec(t_job *j, t_var *var)
{
	if (find_builtins(j) == 0)
	{
		if (ft_strchr(j->p->cmd[0], '/') != 0)
		{
			if (exec_path(j->p->cmd, var) == -1)
				ft_putstr("command not found.\n");
		}
		else
		{
			if (use_execve(j->p->cmd, var) == -1)
				ft_putstr("command not found.\n");
		}
	}
}
