/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 10:52:26 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:49:18 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"

int			cnt_size(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			i++;
		if (str[i] && str[i] == '"' && (i == 0 || str[i - 1] != '\\'))
		{
			i++;
			nb++;
			while (str[i] && str[i] != '"' && (i == 0 || str[i - 1] != '\\'))
				i++;
			i++;
		}
		if (str[i] && str[i] == '\'' && (i == 0 || str[i - 1] != '\\'))
		{
			i++;
			nb++;
			while (str[i] && str[i] != '\'' && (i == 0 || str[i - 1] != '\\'))
				i++;
			i++;
		}
		else if (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
		{
			nb++;
			while (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '
			&& str[i] != '"' && str[i] != '\'' && (i == 0 || str[i - 1] != '\\')))
				i++;
		}
	}
	return (nb);
}

char		**split_space(char *str)
{
	int		i;
	int		k;
	char	**res;
	int		start;

	i = 0;
	k = 0;
	res = malloc(sizeof(char *) * (cnt_size(str) + 1));
	while (str[i])
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			i++;
		if (str[i] && str[i] == '"' && (i == 0 || str[i - 1] != '\\'))
		{
			i++;
			start = i;
			while (str[i] && str[i] != '"' && (i == 0 || str[i - 1] != '\\'))
				i++;
			res[k] = ft_strsub(str, start, i - start);
			k++;
			i++;
		}
		else if (str[i] && str[i] == '\'' && (i == 0 || str[i - 1] != '\\'))
		{
			start = i;
			i++;
			while (str[i] && str[i] != '\'' && (i == 0 || str[i - 1] != '\\'))
				i++;
			res[k] = ft_strsub(str, start, (i + 1) - start);
			k++;
			i++;
		}
		else if (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
		{
			start = i;
			while (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '
			&& str[i] != '"' && str[i] != '\'' && (i == 0 || str[i - 1] != '\\')))
				i++;
			printf("i: %d, s,: %d\n", i, start);
			res[k] = ft_strsub(str, start, i - start);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}

void		list_add(t_replace **replace, char *array)
{
	t_replace	*next;
	t_replace	*start;

	start = (*replace);
	while ((*replace)->next)
		(*replace) = (*replace)->next;
	next = malloc(sizeof(t_replace));
	next->name = ft_strdup(array);
	next->next = NULL;
	(*replace)->next = next;
	(*replace) = start;
}

void		init_replace(t_replace **replace)
{
	(*replace) = malloc(sizeof(t_replace));
	(*replace)->name = ft_strdup("");
	(*replace)->next = NULL;
}

void		free_replace(t_replace *replace)
{
	t_replace	*tmp;

	while (replace)
	{
		ft_strdel(&replace->name);
		tmp = replace;
		replace = replace->next;
		free(&tmp);
	}
}
