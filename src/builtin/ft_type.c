/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 14:07:25 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 17:21:44 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtin.h"

/*
** verifie en premier builtin, puis shell ?
*/

int		find_type(char *function, t_ft *global)
{
	int i;
	char **path_function;

	i = -1;
	printf("%s\n", function);
	while (++i < LEN_BUILTIN_LIST)
	{
		if (ft_strcmp(function, g_builtin_list[i].name) == 0)
			return (1);
	}
	path_function = ft_strsplit(ft_get_val("PATH", &global->env), ' ');
	i = -1;
	while (path_function[++i] != NULL)
	{
		if (ft_strcmp(function, path_function[i]) == 0)
			return (1);
	}
	return (0);
}

int		ft_type(char **argv, t_ft *global)
{
	printf("%d\n", find_type(argv[1], global));
	return (0);
}
