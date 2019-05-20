/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_lexeur.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 11:29:05 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 20:36:53 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"

void		jump_space(char *buf, int *i)
{
	while (buf[*i] && ((buf[*i] >= 9 && buf[*i] <= 13) || buf[*i] == ' '))
		(*i)++;
}

void		fill_struct(t_lexeur *res, char *word, enum e_token token,
char *red)
{
	if (word)
		res->word = ft_strdup(word);
	else
		res->word = NULL;
	res->token = token;
	if (red)
		res->redirection = ft_strdup(red);
	else
		res->redirection = NULL;
	res->fd = -1;
	ft_strdel(&word);
	ft_strdel(&red);
}

t_lexeur	*fill_lex_redirection(char *buf, t_lexeur *res, int *i, int token)
{
	if (token == 4 || token == 5 || token == 6 || token == 7)
	{
		fill_struct(res, NULL, token, fill_redirection(buf, i, token));
		return (res);
	}
	fill_struct(res, NULL, token, NULL);
	*i += g_fill_token[token].size;
	return (res);
}

t_lexeur	*fill_lex_while(char *buf, int *i, int token)
{
	t_lexeur	*res;

	res = malloc(sizeof(t_lexeur));
	if (buf[*i] && token != -1)
		return (fill_lex_redirection(buf, res, i, token));
	else
	{
		fill_struct(res, buf, -1, NULL);
		return (res);
	}
	return (NULL);
}

t_lexeur	**fill_lex(char **buf, t_lexeur **array)
{
	int			i;
	int			j;
	int			k;
	t_lexeur	*tmp;

	i = 0;
	j = 0;
	while (buf[i])
	{
		printf("buf[%d]: _%s_\n", i, buf[i]);
		i++;
	}
	array = malloc(sizeof(t_lexeur *) * (i + 1));
	i = 0;
	while (buf[i])
	{
		k = 0;
		if (ft_strcmp(buf[i], "") == 0)
			break ;
		if ((tmp = find_fd(buf[i], 0)) != NULL)
			array[j] = tmp;
		else if (buf[i])
			array[j] = fill_lex_while(buf[i], &k, find_token(buf[i], k));
		i++;
		j++;
	}
	array[j] = NULL;
	check_redirection(&array);
	del_back_slash(&array);
	return (array);
}
