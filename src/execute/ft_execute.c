/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execute.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <shthevak@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 14:50:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 16:46:46 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "execute.h"

int		get_env_len(t_var **var)
{
	int			i;
	t_var	*list;

	i = 0;
	list = *var;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

char	**get_env_tab(t_var **var)
{
	t_var	*list;
	int			i;
	char		**tab;
	char		c;

	list = *var;
	if (!(tab = malloc(sizeof(tab) * (get_env_len(var) + 1))))
		return (NULL);
	i = 0;
	while (list)
	{
		tab[i] = ft_strjoin(list->var, "=");
		ft_strjoin_free(&(tab[i]), list->val);
		list = list->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_execute_line(char *str, t_ft *ft)
{
	char	**en;
	char	**com;

	com = ft_strsplit(str, ' ');
	en = get_env_tab(&(ft->env));
	ft_free_tab(en);
	ft_free_tab(com);
}
