/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 14:27:36 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 14:13:35 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/exec.h"
#include "../../includes/lexeur.h"

int		ft_error_cd(char *error, char *name)
{
	ft_putstr("cd: ");
	ft_putstr(error);
	ft_putstr(": ");
	ft_putstr(name);
	ft_putchar('\n');
	return (1);
}

int		ft_change_dir(char *path, t_var **var, char *old)
{
	char	path_pwd[1000];

	if (chdir(path) == -1)
	{
		if (access(path, F_OK))
			return (ft_error_cd(CD_NO_FILE, path));
		else if (access(path, R_OK | W_OK | X_OK))
			return (ft_error_cd(CD_NO_RIGHTS, path));
		return (1);
	}
	free(path);
	getcwd(path_pwd, 1000);
	add_list_env(var, ENVIRONEMENT, "PWD", ft_strdup(path_pwd));
	add_list_env(var, ENVIRONEMENT, "OLDPWD", ft_strdup(old));
	return (0);
}

int		ft_cd_special(char *name, char *path_pwd, t_var **var)
{
	if (ft_get_val(name, *var, ENVIRONEMENT) == NULL)
	{
		if (ft_strcmp(name, "HOME") == 0)
			ft_putendl(CD_NO_HOME);
		else if (ft_strcmp(name, "OLDPWD") == 0)
			ft_putendl(CD_NO_OLDPWD);
		else
			ft_putendl(CD_NO_ENV);
	}
	else
	{
		return (ft_change_dir(ft_strdup(ft_get_val(name, *var, 0)),
			var, path_pwd));
	}
	return (1);
}

int		ft_cd(t_process *p, t_var **var)
{
	char	path_pwd[1000];
	char	*path;
	char	*buf;

	if (ft_tabclen(p->cmd) > 2)
	{
		ft_putendl(ARGUMENTS);
		return (1);
	}
	getcwd(path_pwd, 1000);
	if (p->cmd[1] == NULL)
		return (ft_cd_special("HOME", path_pwd, var));
	else if (p->cmd[1][0] == '/')
		return (ft_change_dir(ft_strdup(p->cmd[1]), var, path_pwd));
	else if (ft_strcmp(p->cmd[1], "-") == 0)
		return (ft_cd_special("OLDPWD", path_pwd, var));
	else
	{
		ft_change_dir(buf = ft_strjoin(path_pwd,
			(path = ft_strjoin("/", p->cmd[1]))), var, path_pwd);
		free(path);
	}
	return (1);
}
