/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_replpace.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 17:41:43 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 17:43:05 by mdelarbr    ###    #+. /#+    ###.fr     */
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
		if (ft_strcmp(tmp, start->name) == 0 && start->type == 0)
		{
			ft_strdel(&tmp);
			return (start->data);
		}
		start = start->next;
	}
	ft_strdel(&tmp);
	return (ft_strdup(""));
}
