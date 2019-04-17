/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   var_replace.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 17:44:11 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 13:10:53 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/shell.h"

char		*check_var_alias(t_env *env, char *str)
{
	t_env	*start;
	char	*tmp;

	start = env;
	while (start)
	{
		if ((ft_strcmp(start->name, str) == 0) && start->type != ENVIRONEMENT)
		{
			ft_strdel(&str);
			return (start->data);
		}
		start = start->next;
	}
	tmp = ft_strdup(str);
	ft_strdel(&str);
	return (tmp);
}

int			f_check_var_alias(t_env *env, char *str)
{
	t_env	*start;

	start = env;
	while (start)
	{
		if ((ft_strcmp(start->name, str) == 0) && start->type != ENVIRONEMENT)
			return (1);
		start = start->next;
	}
	return (0);
}
