/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alias.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 17:50:35 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 18:25:49 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"

char		*replace_alias_while(t_replace *tmp_r, t_var *var, char *array,
char *res)
{
	while (tmp_r)
	{
		if (ft_strcmp(tmp_r->name, var->name) == 0)
		{
			res = ft_strdup(var->name);
			ft_strdel(&array);
			return (res);
		}
		tmp_r = tmp_r->next;
	}
	return (res = ft_strdup(var->data));
}

char		*replace_alias(char *array, t_var *var, t_replace *replace)
{
	int			i;
	char		*res;
	t_replace	*tmp_r;

	tmp_r = replace;
	res = ft_strdup("");
	i = 0;
	while (var && (ft_strcmp(array, var->name) != 0 && var->type != ALIAS))
		var = var->next;
	if (!var)
	{
		res = ft_strdup(array);
		ft_strdel(&array);
		return (res);
	}
	res = replace_alias_while(tmp_r, var, array, res);
	list_add(&replace, array);
	ft_strdel(&array);
	return (res);
}
