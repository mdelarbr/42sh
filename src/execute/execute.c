/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 14:31:05 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 13:38:35 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "execute.h"

int			function_is_builtin(char **command, t_ft *ft_global)
{
	//if (ft_strcmp(command[1], "cd") == 0)
	//	ft_cd(command, ft_global);
	/*else if (ft_strcmp(func_name, "test") == 0)
		ft_test(argv);
	else if (ft_strcmp(func_name, "echo") == 0)
		ft_echo(argv, *env);
	else if (ft_strcmp(func_name, "exit") == 0)
	{
		*end_shell = 0;
		return (0);
	}
	else if (ft_strcmp(func_name, "setenv") == 0)
		ft_setenv(argv, env);
	else if (ft_strcmp(func_name, "unsetenv") == 0)
		ft_unsetenv(argv, env);
	else if (ft_strcmp(func_name, "env") == 0)
		ft_env(argv, *env);
	else
		return (1);*/
	return (0);
}

int	ft_execute(char *exec, char **opt, char **env)
{
	int		w;
	pid_t	p;

	p = fork();
	if (p == -1)
		return (-1);
	if (p == 0)
	{
		if (execve(exec, opt, env) == -1)
			return (0);
	}
	else
		wait(&w);
	return (1);
}

void		execute(char **command, t_ft *ft_global)
{
	function_is_builtin(command, ft_global);
}
