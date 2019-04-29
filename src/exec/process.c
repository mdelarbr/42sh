/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/26 14:34:20 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 17:35:12 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/lexeur.h"

int			cnt_process(t_lexeur **res, int i)
{
	int		nb;

	nb = 0;
	while (res[i] && (res[i]->word || res[i]->redirection))
	{
		i++;
		nb++;
	}
	return (nb);
}

void		fill_cmd(t_lexeur **res, t_job **j, int *k, int *i)
{
	if (res[*i]->token == 4)
		(*j)->p->token = ft_strdup(ft_strjoin(">>", res[*i]->redirection));
	else if (res[*i]->token == 5)
		(*j)->p->token = ft_strdup(ft_strjoin(">", res[*i]->redirection));
	else if (res[*i]->token == 6)
		(*j)->p->token = ft_strdup(ft_strjoin("<<", res[*i]->redirection));
	else if (res[*i]->token == 7)
		(*j)->p->token = ft_strdup(ft_strjoin("<", res[*i]->redirection));
	else
	{
		if (!res[*i]->redirection)
			(*j)->p->token = ft_strdup("");
		(*j)->p->cmd[*k] = ft_strdup(res[*i]->word);
		(*k)++;
	}
	(*i)++;
}

void		change_job(t_job **j, t_process **start)
{
	(*j)->p->next = NULL;
	(*j)->p = *start;
	(*j) = (*j)->next;
	(*j)->p = malloc(sizeof(t_process));
	*start = (*j)->p;
}

void		fill_process_split(t_job **j, t_lexeur **res, int *i)
{
	int		k;

	k = (*i);
	while (res[k] && (res[k]->word || (res[k]->token == 4 ||
	res[k]->token == 5 || res[k]->token == 6 || res[k]->token == 7)))
		k++;
	if (res[k] && res[k]->token == 0)
		(*j)->p->split = 'A';
	else if (res[k] && res[k]->token == 2)
		(*j)->p->split = '|';
	else if (res[k] && res[k]->token == 3)
		(*j)->p->split = 'P';
	else
		(*j)->p->split = '\0';
}

int			fill_process_while(t_lexeur **res, t_job **j, t_process **start,
int *i)
{
	int		k;

	k = 0;
	fill_process_split(j, res, i);
	(*j)->p->cmd = malloc(sizeof(char *) * (cnt_process(res, *i) + 1));
	while (res[*i] && (res[*i]->word || res[*i]->redirection))
		fill_cmd(res, j, &k, i);
	(*j)->p->cmd[k] = NULL;
	if (res[*i] && (res[*i]->token != 1 && res[*i]->token != 8 && res[*i]->token
	!= 4 && res[*i]->token != 5 && res[*i]->token != 6 && res[*i]->token != 7))
	{
		(*j)->p->next = malloc(sizeof(t_process));
		(*j)->p = (*j)->p->next;
		(*j)->p->status = '\0';
	}
	else if ((res[*i] && (*j)->next != NULL) && (res[*i]->token == 1 ||
	res[*i]->token == 8))
		change_job(j, start);
	else
	{
		(*j)->p->next = NULL;
		(*j)->p = *start;
		return (0);
	}
	return (1);
}

void		fill_process(t_job *j, t_lexeur **res)
{
	int			i;
	t_process	*start;

	i = 0;
	j->p = malloc(sizeof(t_process));
	start = j->p;
	j->p->status = '\0';
	while (res[i])
	{
		if (fill_process_while(res, &j, &start, &i) == 0)
			break ;
		i++;
	}
}
