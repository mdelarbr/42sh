/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/26 14:34:20 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 18:14:46 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/lexeur.h"

int			cnt_process(t_lexeur **res, int i)
{
	int		nb;

	nb = 0;
	while (res[i] && res[i]->word)
	{
		i++;
		nb++;
	}
	return (nb);
}

void		fill_cmd(t_lexeur **res, t_job *j, int *k, int *i)
{
	j->p->cmd[*k] = ft_strdup(res[*i]->word);
	(*i)++;
	(*k)++;
}

void		change_job(t_job **j, t_process **start)
{
	(*j)->p->next = NULL;
	(*j)->p = *start;
	(*j) = (*j)->next;
	(*j)->p = malloc(sizeof(t_process));
	*start = (*j)->p;
}

/* TODO faire ensorte que les >> ou << etc ne suis pas pris comme des process.*/

int			fill_process_while(t_lexeur **res, t_job **j, t_process **start,
int *i)
{
	int		k;

	k = 0;
	(*j)->p->cmd = malloc(sizeof(char *) * (cnt_process(res, *i) + 1));
	while (res[*i] && res[*i]->word)
		fill_cmd(res, (*j), &k, i);
	(*j)->p->cmd[k] = NULL;
	if (res[*i] && (res[*i]->token != 1 && res[*i]->token != 8))
	{
		(*j)->p->next = malloc(sizeof(t_process));
		(*j)->p = (*j)->p->next;
		init_process((*j)->p);
	}
	else if (res[*i] && (*j)->next != NULL)
		change_job(j, start);
	else
	{
		(*j)->p->next = NULL;
		(*j)->p = *start;
		return (0);
	}
	(*i)++;
	return (1);
}

void		fill_process(t_job *j, t_lexeur **res)
{
	int			i;
	t_process	*start;

	i = 0;
	j->p = malloc(sizeof(t_process));
	start = j->p;
	init_process(j->p);
	while (res[i])
	{
		if (fill_process_while(res, &j, &start, &i) == 0)
			break ;
	}
}
