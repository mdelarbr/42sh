/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:43:41 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/24 16:09:00 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/lexeur.h"

int			cnt_res(t_lexeur **res, int i)
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

void		fill_process(t_job *j, t_lexeur **res, int *i)
{
	int		k;
	int		tmp;

	k = 0;
	tmp = (*i);
	j->p = malloc(sizeof(t_process));
	j->p->cmd = malloc(sizeof(char*) * (cnt_res(res, tmp) + 1));
	while (res[*i] && (res[*i]->token))
	{
		j->p->cmd[k] = ft_strdup(res[*i]->word);
		k++;
		(*i)++;
	}
	j->p->cmd[k] = NULL;
	j->p->next = NULL;
}

void		print_job(t_job *j)
{
	int		job;
	int		i;
	int		process;

	job = 0;
	i = 0;
	process = 0;
	while (j)
	{
		printf("\nj[%d]->next: _%p_\tsplit: _%c_\n", job, j->next, j->split);
		job++;
		/*while (j->p)
		{
			printf("\np[%d]->next: _%p_\n", process, j->p->next);
			process++;
			while (j->p->cmd[i])
			{
				printf("\ncmd[%d]-> _%s_\n", i, j->p->cmd[i]);
				i++;
			}
			j->p = j->p->next;
		}*/
		process = 0;
		j = j->next;
	}
}

void		init_job(t_job *j)
{
	j->split = '\0';
	j->completed = '\0';
	j->stopped = '\0';
}

void		fill_job(t_job *j, t_lexeur **res)
{
	int			i;
	int			k;
	t_job		*start;

	start = j;
	i = 0;
	k = 0;
	while (res[i])
	{
		if (res[i]->token == 1 || res[i]->token == 8)
		{
			if (res[i]->token == 1)
				j->split = '&';
			else
				j->split = ';';
			j->next = malloc(sizeof(t_job));
			j = j->next;
			init_job(j);
		}
		if (res[i])
			i++;
	}
	j->next = NULL;
	j = start;
}

int			start_exec(t_lexeur **res)
{
	t_job		*j;

	j = malloc(sizeof(t_job));
	init_job(j);
	fill_job(j, res);
//	fill_process(j, res);
	print_job(j);
	return (0);
}