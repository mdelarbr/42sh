/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:06:30 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 11:18:12 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"

/*
** TODO faire en sorte qu'on puisse exec un builtins au milieu d'autres
** comme ls.
*/

int		make_set(t_process *p, t_var *var)
{
	if (p->cmd[1])
		return (1);
	while (var)
	{
		ft_putstr(var->name);
		ft_putstr("=");
		ft_putstr(var->data);
		ft_putstr("\n");
		var = var->next;
	}
	return (1);
}

int		find_builtins(t_process *p, t_var *var)
{
	if (ft_strcmp(p->cmd[0], "alias") == 0)
		return (main_alias(p, &var));
	if (ft_strcmp(p->cmd[0], "unalias") == 0)
		return (main_unalias(p, &var));
	if (ft_strcmp(p->cmd[0], "set") == 0)
		return (make_set(p, var));
	return (0);
}
