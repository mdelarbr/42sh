/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token_heredoc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bjuarez <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 14:36:04 by bjuarez      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 15:10:20 by bjuarez     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static void	find_word_heredoc(t_pos *pos, t_tok *in, int k, int l)
{
	int	j;

	in->i += 2;
	j = in->i;
	if (!pos->ans[j])
		return ;
	while (pos->ans[j] && (pos->ans[j] <= 32 || pos->ans[j] > 126))
		j++;
	while (pos->ans[j] > 32 && pos->ans[j] <= 126)
	{
		k++;
		j++;
	}
	if (k == 0)
		return ;
	if (!(in->herestr = (char*)malloc(sizeof(char) * (k + 1))))
		return ;
	j -= k;
	k += j - in->i;
	while (j != in->i + k)
		in->herestr[l++] = pos->ans[j++];
	in->herestr[l] = '\0';
}

static void	heredoc_0(t_pos *pos, t_tok *in, t_tokench *tok)
{
	if (in->heredoc == 0 && pos->ans[in->i] == '<'
	&& pos->ans[in->i + 1] == '<')
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return ;
		}
		if (in->quote == 0 && in->dquote == 0)
		{
			find_word_heredoc(pos, in, 0, 0);
			if (in->herestr == NULL)
			{
				pos->error = -1;
				return ;
			}
			in->fullheredoc = ft_strdup("<< ");
			in->fullheredoc = ft_strjoinf(in->fullheredoc, in->herestr, 1);
			maj_token(tok, "<<");
			in->heredoc = 1;
		}
	}
}

void		check_heredoc(t_pos *pos, t_tok *in, t_tokench *tok)
{
	heredoc_0(pos, in, tok);
	heredoc_1(pos, in, tok);
}
