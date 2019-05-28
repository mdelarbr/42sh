/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   var_replace.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 17:44:11 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 09:33:01 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/termcaps.h"

char		*replace_var(t_var *env, char *str)
{
	t_var	*start;
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

int			f_check_var(t_var *env, char *str)
{
	t_var	*start;

	start = env;
	while (start)
	{
		if ((ft_strcmp(start->name, str) == 0) && start->type == LOCAL)
			return (1);
		start = start->next;
	}
	return (0);
}
