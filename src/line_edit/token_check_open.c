/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token_check_open.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bjuarez <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 14:22:08 by bjuarez      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 14:26:28 by bjuarez     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static int	check_nothing(t_pos *pos, t_tok *in)
{
	if (pos->ans[in->i] == 96)
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return (0);
		}
		if (in->quote == 0 && in->heredoc == 0)
		{
			in->nb_quote++;
			if (in->bquote == 1)
				return (0);
			in->bquote = 1;
			return (1);
		}
	}
	return (0);
}

static int	check_nothing2(t_pos *pos, t_tok *in)
{
	if (pos->ans[in->i] == 39)
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return (0);
		}
		if (in->bquote == 0 && in->dquote == 0 && in->heredoc == 0)
		{
			in->nb_quote++;
			if (in->quote == 1)
				return (0);
			in->quote = 1;
			return (1);
		}
	}
	return (0);
}

static int	check_tree_c(t_pos *pos, t_tok *in)
{
	int	mode;

	mode = 0;
	if (pos->ans[in->i] == 34)
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return (0);
		}
		if (in->bquote == 0 && in->quote == 0 &&
			in->heredoc == 0)
		{
			in->nb_dquote++;
			if (in->dquote == 1)
				return (0);
			in->dquote = 1;
			return (1);
		}
	}
	return (0);
}

void		check_first_token(t_pos *pos, t_tok *in, t_tokench *tok)
{
	if (check_nothing(pos, in) == 1)
		maj_token(tok, "`");
	else if (check_nothing2(pos, in) == 1)
		maj_token(tok, "'");
	else if (check_tree_c(pos, in) == 1)
		maj_token(tok, in->dquote_d);
}
