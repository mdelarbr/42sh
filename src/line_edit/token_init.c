/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   token_init.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bjuarez <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 14:51:07 by bjuarez      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/22 14:52:14 by bjuarez     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static void	init_t_tokench(t_tokench *tok)
{
	tok->token = ft_strnew(3);
	tok->end = 0;
	tok->next = NULL;
	tok->prev = NULL;
}

t_tokench	*add_list_back_tok_next(t_tokench *tok)
{
	t_tokench	*new;

	new = NULL;
	if (!(new = (t_tokench*)malloc(sizeof(t_tokench))))
		return (NULL);
	if (tok == NULL)
	{
		init_t_tokench(new);
		return (new);
	}
	else
	{
		while (tok->next != NULL)
			tok = tok->next;
		init_t_tokench(new);
		tok->next = new;
		new->prev = tok;
		return (new);
	}
	free(new);
	return (NULL);
}

void		maj_token(t_tokench *tok, char *c)
{
	tok->token = ft_strcpy(tok->token, c);
	tok = add_list_back_tok_next(tok);
}

void		init_tok(t_tok *in)
{
	in->quote = 0;
	in->dquote = 0;
	in->bquote = 0;
	in->cmdand = 0;
	in->cmdor = 0;
	in->pipe = 0;
	in->heredoc = 0;
	in->herestr = NULL;
	in->fullheredoc = NULL;
	in->i = 0;
	in->n = 0;
	in->mode = 0;
	in->nb_quote = 0;
	in->nb_dquote = 0;
	if (!(in->dquote_d = (char*)malloc(sizeof(char) * 2)))
		return ;
	in->dquote_d[0] = 34;
	in->dquote_d[1] = '\0';
}
