/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token_heredoc_close.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bjuarez <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 14:59:11 by bjuarez      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 15:11:55 by bjuarez     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static int	check_after_heredoc(t_pos *pos, t_tok *in, int j)
{
	j += ft_strlen(in->herestr);
	while (pos->ans[j] <= 32 || pos->ans[j] > 126)
	{
		if (pos->ans[j] == '\n' || pos->ans[j] == '\0')
			return (1);
		j++;
	}
	return (0);
}

static int	check_before_heredoc(t_pos *pos, int j)
{
	j--;
	while (pos->ans[j] <= 32 || pos->ans[j] > 126)
	{
		if (pos->ans[j] == '\n')
			return (1);
		j--;
	}
	return (0);
}

static int	heredoc_1_mode1(t_pos *pos, t_tok *in, t_tokench *tok)
{
	if (ft_strncmp(&pos->ans[in->n], in->herestr, ft_strlen(in->herestr)) == 0)
	{
		if (check_before_heredoc(pos, in->n) == 1)
		{
			if (check_after_heredoc(pos, in, in->n) == 1)
			{
				in->heredoc = 0;
				tok->end = 1;
				in->i = in->n + 1;
				free_heredoc(in);
				return (1);
			}
		}
	}
	return (0);
}

static int	heredoc_1_mode0(t_pos *pos, t_tok *in)
{
	if (ft_strncmp(&pos->ans[in->n], in->herestr, ft_strlen(in->herestr)) == 0)
	{
		if (ft_strncmp(&pos->ans[in->n - 3], in->fullheredoc,
		ft_strlen(in->fullheredoc)) == 0)
			in->n -= 3;
	}
	if (ft_strncmp(&pos->ans[in->n], in->fullheredoc,
	ft_strlen(in->fullheredoc)) == 0)
	{
		in->n += ft_strlen(in->fullheredoc);
		in->i = in->n;
		return (1);
	}
	return (0);
}

void		heredoc_1(t_pos *pos, t_tok *in, t_tokench *tok)
{
	int mode;

	in->n = in->i;
	mode = 0;
	if (in->heredoc == 1 && in->herestr != NULL)
	{
		while (mode == 0 && pos->ans[in->n] != '\0')
		{
			if ((mode = heredoc_1_mode0(pos, in)) == 1)
				break ;
			in->n++;
		}
		while (mode == 1 && pos->ans[in->n] != '\0')
		{
			if (heredoc_1_mode1(pos, in, tok) == 1)
				break ;
			in->n++;
		}
	}
}
