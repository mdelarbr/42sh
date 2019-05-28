/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_export.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 15:23:43 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 14:47:04 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int			ft_export_env(char *name, t_var **ptr_var)
{
	t_var *var;

	var = *ptr_var;
	if (ft_get_val(name, var, LOCAL) == NULL)
		return (0);
	while (var)
	{
		if (ft_strcmp(name, var->name) == 0 && var->type == LOCAL)
		{
			var->type = ENVIRONEMENT;
			return (1);
		}
		var = var->next;
	}
	return (0);
}

int			ft_export(t_process *p, t_var **ptr_var)
{
	int i;

	i = 0;
	while (p->cmd[++i])
	{
		if (ft_export_env(p->cmd[i], ptr_var))
			ft_printf("ok\n");
		else
			ft_printf("not\n");
	}
	return (0);
}
