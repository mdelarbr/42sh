/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_replace.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 17:41:43 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/12 11:57:32 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/termcaps.h"

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

char		*replace_env(t_var *env, char *str, int i)
{
	int		s;
	char	*tmp;
	char	*first;
	char	*res;
	char	*end;
	t_var	*start;

	s = i;
	end = ft_strdup("");
	while (str[i] && str[i] != '$')
		i++;
	first = ft_strsub(str, s, i - s);
	start = env;
	i++;
	s = i;
	while (str[i] && str[i] != '$')
		i++;
	tmp = ft_strsub(str, s, i - s);
	if (str[i])
	{
		s = i;
		while (str[i])
			i++;
		end = ft_strsub(str, s, i - s);
	}
	while (start)
	{
		if (ft_strcmp(tmp, start->name) == 0 && start->type == ENVIRONEMENT)
		{
			res = ft_strjoin(first, start->data);
			ft_strjoin_free(&res, end);
			ft_strdel(&tmp);
			ft_strdel(&first);
			return (res);
		}
		start = start->next;
	}
	ft_strdel(&tmp);
	ft_strdel(&first);
	return (ft_strdup(""));
}
