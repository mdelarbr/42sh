/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:27:56 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 22:06:28 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/shell.h"

char		*env_var(t_env *env, char *str)
{
	t_env	*start;

	start = env;
	while (start)
	{
		if (ft_strcmp(start->name, str) == 0 && start->type == ENVIRONEMENT)
		{
			ft_strdel(&str);
			return (start->data);
		}
		start = start->next;
	}
	ft_strdel(&str);
	return (ft_strdup(""));
}

char		*make_string(char **array)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup("");
	while (array[i])
	{
		ft_strjoin_free(&res, array[i]);
		if (array[i + 1])
			ft_strjoin_free(&res, " ");
		i++;
	}
	return (res);
}

char		*remove_env(t_all *all, char *str)
{
	t_env	*start;
	char	**array;
	char	*tmp;
	int		i;

	i = 0;
	start = all->env;
	array = ft_strsplit(str, ' ');
	while (array[i])
	{
		if (array[i][0] == '$')
		{
			tmp = ft_strsub(array[i], 1, ft_strlen(array[i]));
			array[i] = env_var(all->env, tmp);
		}
		i++;
	}
	ft_strdel(&str);
	tmp = make_string(array);
	dprintf(1, "tmp -> {%s}\n", tmp);
	return (tmp);
}
