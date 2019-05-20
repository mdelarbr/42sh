/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unset.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 15:49:17 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 16:23:26 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int			ft_unset_var(char *name, t_var **ptr_var)
{
	if (remove_list_var(ptr_var, ENVIRONEMENT, name))
		return (1);
	else if (remove_list_var(ptr_var, LOCAL, name))
		return (1);
	return (0);
}

int			ft_unset(t_process *p, t_var **ptr_var)
{
	int i;

	i = 0;
	while (p->cmd[++i])
	{
		if (ft_unset_var(p->cmd[i], ptr_var))
			printf("ok\n");
		else
			printf("not\n");
	}
	return (0);
}
