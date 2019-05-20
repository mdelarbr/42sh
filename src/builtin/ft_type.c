/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 14:14:27 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 15:01:19 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/exec.h"
#include "../../includes/builtin.h"

int				is_builtin(char *function)
{
	int i;

	i = -1;
	while (++i < LEN_BUILTIN_LIST)
	{
		if (ft_strcmp(function, g_builtin_list[i].name) == 0)
			return (1);
	}
	return (0);
}

//int				is_alias()
//{
//
//}

char				is_function(char *function, t_var **var)
{
	char *path_env;
	char **path;
	char *path_function;
	int i;

	i = -1;
	path_env = ft_get_val("PATH",*var, ENVIRONEMENT);
	path = ft_strsplit(path_env, ':');
	while (path[++i])
	{
		path_function = ft_strjoin(ft_strjoin(path[i], "/"), function);
		if (ft_file_xrights(path_function))
		{
			printf("%s\n", path_function);
			return (1);
		}
	}
	if (ft_file_xrights(function))
	{
		printf("fun %s\n", function);
		return (1);
	}
	return (0);
}

int				ft_type(t_process *p, t_var **var)
{
	int i;

	i = 0;
	while (p->cmd[++i])
	{
		if (is_builtin(p->cmd[i]))
			printf("%s\n", "ok");
		else if (is_function(p->cmd[i], var))
			printf("%s\n", "function");
		else
			printf("%s\n", "not");
	}
	return (0);
}
