/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 14:31:05 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 13:31:33 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "execute.h"

const t_builtin	g_builtin_list[LEN_BUILTIN_LIST] =
{
	{"cd", &ft_cd},
	{"echo", &ft_echo},
	{"test", &ft_test},
	{"exit", &ft_exit},
	{"type", &ft_type}
};

int		function_is_builtin(char **command, t_ft *global)
{
	int i;

	i = -1;
	while (i++ < LEN_BUILTIN_LIST)
	{
		if (ft_strcmp(command[0], g_builtin_list[i].name) == 0)
		{
			g_builtin_list[i].ptr_builtin(command, global);
			return (1);
		}
	}
	return (0);
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
		if (execve(exec, opt, get_env_tab(&global->env)) == -1)
			return(-1);
	}
	else
	{
		wait(&w);
		global->return_last = WEXITSTATUS(w);
	}
	return(1);
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

char		*function_path(char *path_function, char **command, t_ft *global)
{
	char		*buf;
	char		*path;
	int			f;

	path = ft_strjoin(path_function,
		buf = ft_strjoin("/", command[0]));
	free(buf);
	if (access(path, F_OK))
		return (NULL);
	else if (access(path, X_OK))
	{
		ft_putendl(RIGHTS);
		return (NULL);
	}
	return (path);
}

int		ft_execute_bin(char **command, t_ft *global)
{
	char	**path_function;
	char	*path_bin;
	int		f;
	int		i;

	if ((path_function = ft_strsplit(ft_get_val("PATH", &global->env), ':'))
		!= NULL)
	{
		i = -1;
		while (path_function[++i] != NULL)
		{
			if ((path_bin = function_path(path_function[i], command, global)) != NULL)
			{
				printf("%s\n", path_bin);
				if (ft_execute(path_bin, command, global) == 1)
					return (1);
			}
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
