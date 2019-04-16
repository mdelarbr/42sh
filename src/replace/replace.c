/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:27:56 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 16:10:28 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/shell.h"

char		*switch_word(char *str, char *tmp, int i)
{
	char	*res;
	int		j;
	int		k;

	j = 0;
	while (j < i)
		j++;
	res = ft_strsub(str, 0, j);
	if (ft_strcmp(tmp, "") == 0)
		return (res);
	ft_strjoin_free(&res, tmp);
	k = j;
	while (str[k] && ((str[k] < 9 && str[k] > 13) || str[k] != ' '))
		k++;
	j = k;
	while (str[j])
		j++;
	ft_strjoin_free(&res, ft_strsub(str, k, j - k));
	ft_strdel(&str);
	return (res);
}

char		*find_env_var(t_env *env, char *str, int i)
{
	int		s;
	char	*tmp;
	t_env	*start;

	s = i + 1;
	while (str[i] && ((str[i] < 9 && str[i] > 13) || str[i] != ' '))
		i++;
	tmp = ft_strsub(str, s, i - s);
	start = env;
	while (start)
	{
		if (ft_strcmp(tmp, start->name) == 0)
		{
			ft_strdel(&tmp);
			return (start->data);
		}
		start = start->next;
	}
	ft_strdel(&tmp);
	return (ft_strdup(""));
}

char		*print_env(t_all *all, char *str)
{
	t_env	*start;
	char	*tmp;
	int		i;

	i = 0;
	start = all->env;
	while (str[i])
	{
		if (str[i] && str[i] == '$')
		{
			tmp = find_env_var(all->env, str, i);
			str = switch_word(str, tmp, i);
			if (ft_strcmp(str, "") == 0)
			{
				ft_strdel(&tmp);
				ft_strdel(&str);
				return (ft_strdup(""));
			}
			if (str[i])
				i++;
		}
		if (str[i])
			i++;
	}
	return (str);
}
