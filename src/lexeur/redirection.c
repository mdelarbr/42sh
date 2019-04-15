/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redirection.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 17:01:39 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 16:44:46 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"

char			*fill_redirection(char *buf, int *i, int token)
{
	char	*red;
	int		start;
	int		j;

	*i += g_fill_token[token].size;
	jump_space(buf, i);
	start = *i;
	if (token == 4 || token == 5)
	{
		while (buf[*i] && ((buf[*i] < 9 || buf[*i] > 13) && buf[*i] != ' '))
		{
			j = *i;
			if (find_token(buf, j) != -1)
				break ;
			(*i)++;
		}
		red = ft_strsub(buf, start, *i - start);
		return (red);
	}
	return (NULL);
}

t_lexeur		*fill_all(t_lexeur ***tab, int j)
{
	t_lexeur	*res;

	res = malloc(sizeof(t_lexeur));
	if ((*tab)[j]->redirection)
		res->redirection = ft_strdup((*tab)[j]->redirection);
	else
		res->redirection = NULL;
	if ((*tab)[j]->word)
		res->word = ft_strdup((*tab)[j]->word);
	else
		res->word = NULL;
	res->token = (*tab)[j]->token;
	res->fd = (*tab)[j]->fd;
	return (res);
}

void			replace_input(t_lexeur ***tab, t_lexeur ***res, int *i, int *j)
{
	if (!(*tab)[0]->word)
	{
		(*res)[*j] = malloc(sizeof(t_lexeur));
		(*res)[*j]->token = (*tab)[*i + 1]->token;
		(*res)[*j]->redirection = ft_strdup("");
		(*res)[*j]->word = NULL;
		(*res)[*j]->fd = (*tab)[*i + 1]->fd;
		(*i)++;
	}
	else if ((*tab)[*i + 1] && ((*tab)[*i + 1]->token == 6
	|| (*tab)[*i + 1]->token == 7))
	{
		(*res)[*j] = malloc(sizeof(t_lexeur));
		(*res)[*j]->token = (*tab)[*i + 1]->token;
		(*res)[*j]->redirection = ft_strdup((*tab)[*i]->word);
		(*res)[*j]->word = NULL;
		(*res)[*j]->fd = (*tab)[*i + 1]->fd;
		(*i)++;
	}
	else
	{
		(*res)[*j] = (*tab)[*i];
		(*res)[*j] = fill_all(tab, *i);
	}
	(*i)++;
	(*j)++;
}

t_lexeur		**find_input_redirection(t_lexeur ***tab)
{
	int			i;
	int			j;
	t_lexeur	**res;

	j = 0;
	i = 0;
	while ((*tab)[j])
		j++;
	res = malloc(sizeof(t_lexeur *) * (j));
	j = 0;
	while ((*tab)[i])
	{
		replace_input(tab, &res, &i, &j);
	}
	res[j] = NULL;
	return (res);
}

t_lexeur		**check_redirection(t_lexeur ***tab)
{
	int		j;

	j = 0;
	while ((*tab)[j])
	{
		if ((*tab)[j]->token == 6 || (*tab)[j]->token == 7)
			return ((*tab) = find_input_redirection(tab));
		j++;
	}
	return ((*tab));
}
