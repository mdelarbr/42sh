/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token_check_close.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bjuarez <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 14:26:46 by bjuarez      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 14:55:57 by bjuarez     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int			check_close_nothing(t_pos *pos, t_tok *in)
{
	if (pos->ans[in->i] == 96)
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return (0);
		}
		if (in->quote == 0)
			return (1);
	}
	return (0);
}

int			check_close_nothing2(t_pos *pos, t_tok *in)
{
	if (pos->ans[in->i] == 39)
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return (0);
		}
		if (in->bquote == 0 && in->dquote == 0)
			return (1);
	}
	return (0);
}

int			check_close_tree(t_pos *pos, t_tok *in)
{
	if (pos->ans[in->i] == 34)
	{
		if (in->i != 0)
		{
			if (pos->ans[in->i - 1] == 92)
				return (0);
		}
		if (in->bquote == 0 && in->quote == 0)
			return (1);
	}
	return (0);
}

void		check_mode_1_2(t_tok *in, t_tokench *tok, char *c)
{
	if (in->mode == 1 && ft_strncmp(tok->token, c, 1)
		== 0 && in->nb_quote > 1 && in->heredoc == 0)
	{
		tok->end = 1;
		in->bquote = 0;
		in->quote = 0;
		in->nb_quote = 0;
		in->mode = 5;
		return ;
	}
	if (in->mode == 2 && ft_strncmp(tok->token, c, 1)
		== 0 && in->nb_dquote > 1 && in->heredoc == 0)
	{
		tok->end = 1;
		in->dquote = 0;
		in->nb_dquote = 0;
		in->mode = 5;
		return ;
	}
}

t_tokench	*check_close(t_tokench *tok, char *c, t_tok *in)
{
	int	check;

	check = 0;
	while (tok && in->mode != 5)
	{
		check_mode_1_2(in, tok, c);
		if (in->mode == 5)
			break ;
		if (tok->prev == NULL)
			break ;
		tok = tok->prev;
	}
	return (tok);
}
