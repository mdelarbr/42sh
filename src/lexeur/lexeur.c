/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexeur.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 13:48:08 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 09:36:47 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/check_error.h"

t_token g_fill_token[10] =
{
	{"&&", 2, T_AND},
	{"&", 1, T_EXEC_SIM},
	{"||", 2, T_OR},
	{"|", 1, T_PIPE},
	{">>", 2, T_OUT_D},
	{">", 1, T_OUT_S},
	{"<<", 2, T_IN_D},
	{"<", 1, T_IN_S},
	{";", 1, T_SEMI},
	{NULL, 0, -1}
};

int			find_token(char *buf, int i)
{
	int	k;
	int	j;
	int	token;

	token = 0;
	while (g_fill_token[token].name != NULL)
	{
		k = i;
		j = 0;
		while (j <= g_fill_token[token].size)
		{
			if (!buf[k] || buf[k] != g_fill_token[token].name[j])
				break ;
			j++;
			k++;
		}
		if (j == g_fill_token[token].size)
			return (g_fill_token[token].token);
		token++;
	}
	return (g_fill_token[token].token);
}

void		cnt_wrd_while(char *buf, int *i, int *cnt, int token)
{
	if (buf[*i] && (token != -1))
	{
		(*cnt)++;
		(*i) += g_fill_token[token].size;
	}
	else if (buf[*i] && ((buf[*i] >= 9 && buf[*i] <= 13) || buf[*i] == ' '))
		jump_space(buf, i);
	else if (buf[*i] && ((buf[*i] < 9 || buf[*i] > 13) && buf[*i] != ' '))
		cnt_solve_back_slash(buf, i, cnt);
	else
		(*i)++;
}

int			cnt_wrd(char *buf)
{
	int		i;
	int		cnt;
	int		token;

	i = 0;
	cnt = 0;
	jump_space(buf, &i);
	while (buf[i])
	{
		token = find_token(buf, i);
		cnt_wrd_while(buf, &i, &cnt, token);
	}
	return (cnt);
}

int			start_lex(char *str)
{
	int			i;
	int			j;
	t_lexeur	**tab;

	tab = NULL;
	i = 0;
	j = 0;
	if ((check_error(str)) == -1)
		return (-1) ;
	tab = fill_lex(str, tab);
	while (tab[j])
	{
		printf("tab[%d].word: {%s}\ttab[%d].token: {%d}\ttab[%d].redirection: {%s}\tfd: %d\n", j, tab[j]->word, j, tab[j]->token, j, tab[j]->redirection, tab[j]->fd);
		puts("-----------------------------------------------------------------------");
		j++;
	}
	return (0);
}
