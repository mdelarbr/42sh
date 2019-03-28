/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 14:31:05 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 11:49:17 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "execute.h"

int		function_is_builtin(char **command, t_ft *global)
{
	if (ft_strcmp(command[0], "cd") == 0)
		ft_cd(command, global);
	else if (ft_strcmp(command[0], "echo") == 0)
		ft_echo(command, global);
	else if (ft_strcmp(command[0], "exit") == 0)
		global->end_shell = 0;
	else if (ft_strcmp(command[0], "test") == 0)
		ft_test(command);
	else
		return (0);
	/*else if (ft_strcmp(func_name, "test") == 0)
		ft_test(argv);
	else if (ft_strcmp(func_name, "setenv") == 0)
		ft_setenv(argv, env);
	else if (ft_strcmp(func_name, "unsetenv") == 0)
		ft_unsetenv(argv, env);
	else if (ft_strcmp(func_name, "env") == 0)
		ft_env(argv, *env);*/
	return (1);
}

int		ft_execute(char *exec, char **opt, t_ft *global)
{
	int		w;
	pid_t	p;

	p = fork();
	if (p == -1)
		return (-1);
	if (p == 0)
	{
		execve(exec, opt, get_env_tab(&global->env));
	}
	else
	{
		wait(&w);
		global->return_last = WEXITSTATUS(w);
	}
	exit(1);
}

int		error_path_function(char *path)
{
	if (access(path, F_OK))
		return (1);
	else if (access(path, X_OK))
		ft_putendl(RIGHTS);
	else
		return (0);
	return (1);
}

int		function_path(char *path_function, char **command, t_ft *global)
{
	char		*buf;
	char		*path;
	int			f;

	path = ft_strjoin(path_function,
		buf = ft_strjoin("/", command[0]));
	free(buf);
	if (error_path_function(path) == 1)
		return (-1);
	if ((f = ft_execute(path, command, global)) <= 0)
	{
		free(path);
		return (f);
	}
	free(path);
	return (1);
}

int		ft_execute_bin(char **command, t_ft *global)
{
	char	**path_function;
	int		f;
	int		i;

	if ((path_function = ft_strsplit(ft_get_val("PATH", &global->env), ':'))
		!= NULL)
	{
		i = -1;
		while (path_function[++i] != NULL)
		{
			if (function_path(path_function[i], command, global) == 1)
				return (1);
		}
	}
	if ((f = ft_execute(command[0], command, global)) <= 0)
		return (1);
	ft_putstr(COMMAND_NOT_FOUND);
	ft_putstr(command[0]);
	ft_putchar('\n');
	return (0);
}

void	print_global(t_ft *global)
{
	printf("last: %d\n", global->return_last);
}

void	execute(char **command, t_ft *global)
{
	if (!function_is_builtin(command, global))
	{
		if (!ft_execute_bin(command, global))
			global->return_last = 127;
	}
	print_global(global);
}
