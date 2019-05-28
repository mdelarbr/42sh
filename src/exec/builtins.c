/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:06:30 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 16:21:06 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/builtin.h"

/*
** TODO faire en sorte qu'on puisse exec un builtins au milieu d'autres
** comme ls.
*/

const t_builtin	g_builtin_list[LEN_BUILTIN_LIST] =
{
	{"test", &ft_test},
	{"alias", &main_alias},
	{"unalias", &main_unalias},
	{"set", &ft_set},
	{"echo", &ft_echo},
	{"cd", &ft_cd},
	{"type", &ft_type},
	{"export", &ft_export},
	{"unset", &ft_unset}
};

int		find_builtins(t_process *p, t_var *var)
{
	int i;

	i = -1;
	while (++i < LEN_BUILTIN_LIST)
	{
		if (ft_strcmp(p->cmd[0], g_builtin_list[i].name) == 0)
		{
			g_builtin_list[i].ptr_builtin(p, &var);
			return (1);
		}
	}
	return (0);
}
