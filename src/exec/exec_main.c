/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_main.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 11:29:02 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 20:03:39 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"

void		ft_tabfree(char **res)
{
	int i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

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
		{
			ft_tabfree(path);
			return (0);
		}
		i++;
		ft_strdel(&tmp);
	}
	ft_strdel(&tmp);
	ft_tabfree(path);
	return (-1);
}

int			exec_path(char **res, t_var *var)
{
	if (access(res[0], F_OK) == 0)
		return (solve_execve(res[0], res, var));
	return (-1);
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
		{
			ft_tabfree(array);
			return (-1);
		}
	}
	else
		wait(&pid);
	ft_tabfree(array);
	return (1);
}

int			main_exec_while(t_process *p, t_var *var)
{
	if (find_builtins(p, var) == 0)
	{
		if (ft_strchr(p->cmd[0], '/') != 0)
		{
			if (exec_path(p->cmd, var) != 1)
			{
				cnf_print_error(p->cmd[0]);
				return (-1);
			}
		}
		else
		{
			if (use_execve(p->cmd, var) == -1)
			{
				cnf_print_error(p->cmd[0]);
				return (-1);
			}
		}
	}
	return (0);
}

void		main_exec(t_job *j, t_var *var)
{
	t_process	*tmp;

	while (j)
	{
		tmp = j->p;
		while (j->p)
		{
			if (j->p->next && j->p->split != '\0')
			{
				if (main_option_exec((&j->p), (&j->p->next), var) == -1)
					break ;
			}
			else if (main_exec_while(j->p, var) == -1)
				return ;
			j->p = j->p->next;
		}
		j = j->next;
	}
}
