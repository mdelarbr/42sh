/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 14:27:36 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 12:14:27 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtin.h"

int		ft_error_cd(char *error, char *name)
{
	ft_putstr("cd: ");
	ft_putstr(error);
	ft_putstr(": ");
	ft_putstr(name);
	ft_putchar('\n');
	return (1);
}

int		ft_change_dir(char *path, t_ft *global, char *old)
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
	ft_add_var_elem(global->env);
	if (ft_get_val(global->env, "OLDPWD") != NULL)
		add_list_env(env, "OLDPWD", old);
	return (0);
}

int		ft_cd_special(char *name, char *path_pwd, t_ft *global)
{
	if (search_list_env(*env, name) == NULL)
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
		return (ft_change_dir(ft_strdup(search_list_env(*env, name)),
			global, path_pwd));
	}
	return (1);
}

int		ft_cd(char **argv, t_ft *ft_global)
{
	char	path_pwd[1000];
	char	*path;
	char	*buf;

	if (ft_tabclen(argv) > 2)
	{
		ft_putendl(ARGUMENTS);
		return (1);
	}
	getcwd(path_pwd, 1000);
	if (argv[1] == NULL)
		return (ft_cd_special("HOME", path_pwd, ft_global));
	else if (argv[1][0] == '/')
		return (ft_change_dir(ft_strdup(argv[1]), ft_global, path_pwd));
	else if (ft_strcmp(argv[1], "-") == 0)
		return (ft_cd_special("OLDPWD", path_pwd, ft_global));
	else
	{
		ft_change_dir(buf = ft_strjoin(path_pwd,
			(path = ft_strjoin("/", argv[1]))), ft_global, path_pwd);
		free(path);
	}
	return (1);
}
