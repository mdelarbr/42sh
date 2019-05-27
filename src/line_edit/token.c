/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bjuarez <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 08:40:32 by bjuarez      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 09:19:29 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static int	verif_token(char *str)
{
	if (ft_strncmp(str, "&&", 2) == 0)
		return (1);
	if (ft_strncmp(str, "||", 2) == 0)
		return (2);
	if (ft_strncmp(str + 1, "|", 1) == 0 && ft_strncmp(str, "\\|", 2) != 0)
		return (3);
	return (0);
}

static int	find_last_token(char *ans)
{
	int j;
	int check;

	j = 0;
	check = 0;
	while (ans[j])
		j++;
	while (j >= 0 && (ans[j] <= 32 || ans[j] > 126))
		j--;
	j--;
	if (j > 0 && ans[j - 1] == 92)
		return (0);
	if (j >= 0 && (check = verif_token(&ans[j])) != 0)
		return (check);
	return (0);
}

static void	check_close_token(t_pos *pos, t_tok *in, t_tokench *tok)
{
	if (check_close_nothing(pos, in) == 1 && in->mode != 5)
	{
		in->mode = 1;
		tok = check_close(tok, "`", in);
	}
	if (check_close_nothing2(pos, in) == 1 && in->mode != 5)
	{
		in->mode = 1;
		check_close(tok, "'", in);
	}
	if (check_close_tree(pos, in) == 1 && in->mode != 5 && in->bquote != 1)
	{
		in->mode = 2;
		check_close(tok, in->dquote_d, in);
	}
	in->mode = 0;
}

static int	check_in(t_pos *pos, t_tok *in)
{
	if (in->heredoc == 1)
		return (0);
	if (in->quote == 1)
		return (0);
	if (in->dquote > 0)
		return (0);
	if (in->bquote == 1)
		return (0);
	if (find_last_token(pos->ans) < 4 && find_last_token(pos->ans) > 0
		&& in->quote != 1 && in->dquote != 1 && in->bquote != 1)
		return (0);
	return (1);
}

void		check_token(t_pos *pos, t_tok *in, t_tokench *tok)
{
	tok = NULL;
	in->i = 0;
	tok = add_list_back_tok_next(tok);
	tok->prev = NULL;
	while (pos->ans && pos->is_complete != -1 && pos->ans[in->i] != '\0')
	{
		while (tok && tok->next != NULL)
			tok = tok->next;
		check_first_token(pos, in, tok);
		check_close_token(pos, in, tok);
		check_heredoc(pos, in, tok);
		if (pos->ans[in->i] != '\0')
			in->i++;
	}
	pos->is_complete = check_in(pos, in);
	free_all_check_token(in, tok);
}
