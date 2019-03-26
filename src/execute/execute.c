/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 14:31:05 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 14:07:04 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "execute.h"

int			function_is_builtin(char **command, t_ft *global)
{
	if (ft_strcmp(command[0], "cd") == 0)
		ft_cd(command, global);
	else if (ft_strcmp(command[0], "echo") == 0)
		ft_echo(command, global);
	else if (ft_strcmp(command[0], "exit") == 0)
		global->end_shell = 0;
	/*else if (ft_strcmp(func_name, "test") == 0)
		ft_test(argv);
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

void		execute(char **command, t_ft *global)
{
	function_is_builtin(command, global);
}
