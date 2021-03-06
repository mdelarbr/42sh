/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:27:56 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 08:42:21 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/termcaps.h"
#include "../../includes/alias.h"

void		check_spe_free(t_alias **alias, char *ret)
{
	ft_strdel(&(*alias)->data);
	(*alias)->data = ft_strdup(ret);
	ft_strdel(&ret);
}

int			check_spe(t_alias *alias, t_var *var)
{
	char	*tmp;
	char	*ret;
	int		i;

	while (alias)
	{
		i = -1;
		while (alias->data[++i])
		{
			if (alias->data[i] == '$' && alias->data[i + 1] == '_'
			&& (i == 0 || alias->data[i - 1] != '\\'))
			{
				tmp = ft_strdup(ft_get_val("_", var, SPE));
				ret = ft_strsub(alias->data, 0, i);
				ret = ft_strjoinf(ret, tmp, 3);
				ret = ft_strjoinf(ret, ft_strsub(alias->data, i + 2,
				ft_strlen(alias->data)), 3);
				check_spe_free(&alias, ret);
			}
		}
		alias = alias->next;
	}
	return (0);
}

int			remove_env_while(t_alias *alias, t_var *var)
{
	int		done;
	t_alias	*tmp;

	done = 0;
	tmp = alias;
	while (tmp)
	{
		if (tmp->data && condition_find_dollar(tmp->data, 0) &&
		check_backslash_var(tmp->data))
		{
			done = 1;
			replace_var(var, tmp);
			break ;
		}
		tmp = tmp->next;
	}
	return (done);
}

void		free_alias(t_alias *alias)
{
	t_alias *tmp;

	tmp = alias;
	while (alias)
	{
		tmp = alias->next;
		ft_strdel(&alias->data);
		free(alias);
		alias = tmp;
	}
	free(alias);
	alias = NULL;
}

char		**start_split(t_var *start, char *str)
{
	char		**ar;
	t_alias		*al;
	t_replace	*r;

	ar = split_space(str);
	if (!start)
		return (ar);
	al = make_ar_to_list(ar);
	init_replace(&r);
	r->name = ft_strdup(al->data);
	check_tok(al, start, r);
	if (check_alias(al->data, start) == 1 &&
	al->data[0] != '\\')
		replace_alias(al, start, r);
	check_spe(al, start);
	ar = make_list_to_ar(al);
	ft_strdel(&str);
	free_replace(r);
	free_alias(al);
	return (ar);
}
