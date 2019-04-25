/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:43:41 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/25 15:08:53 by mdelarbr    ###    #+. /#+    ###.fr     */
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

void		init_process(t_process *p)
{
	p->completed = '\0';
	p->stopped = '\0';
}

void		fill_process(t_job *j, t_lexeur **res)
{
	int			i;
	int			k;
	t_process	*start;

	i = 0;
	j->p = malloc(sizeof(t_process));
	start = j->p;
	init_process(j->p);
	while (res[i])
	{
		k = 0;
		j->p->cmd = malloc(sizeof(char *) * (cnt_process(res, i) + 1));
		while (res[i] && res[i]->word)
		{
			j->p->cmd[k] = ft_strdup(res[i]->word);
			printf("\ncmd[%d]->_%s_\n", k, j->p->cmd[k]);
			i++;
			k++;
		}
		j->p->cmd[k] = NULL;
		if (res[i] && (res[i]->token != 1 && res[i]->token != 8))
		{
			puts("\nnew: process");
			j->p->next = malloc(sizeof(t_process));
			j->p = j->p->next;
			init_process(j->p);
		}
		else if (res[i] && j->next != NULL)
		{
			puts("\nnew: job");
			j->p->next = NULL;
			printf("diff1: -%p-\n", j->p);
			j->p = start;
			j = j->next;
			j->p = malloc(sizeof(t_process));
			start = j->p;
			printf("diff2: -%p-\n", j->p);
		}
		else
		{
//			j->p = start;
			puts("\nfini");
			break ;
		}
		i++;
	}
	j->p->next = NULL;
}

void		print_job(t_job *j)
{
	int		job;
	int		i;
	int		process;
	t_process	*start;

	job = 0;
	i = 0;
	process = 0;
	while (j)
	{
		printf("\n---jobs---[%d]->next: _%p_\tsplit: _%c_\n", job, j->next, j->split);
		job++;
		start = j->p;
		while (j->p)
		{
			printf("--process--[%d]->next: _%p_\n", process, j->p->next);
			process++;
			while (j->p->cmd[i])
			{
				printf("cmd[%d]-> _%s_\n", i, j->p->cmd[i]);
				i++;
			}
			i = 0;
			j->p = j->p->next;
		}
		j->p = start;
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
			if (res[i + 1])
			{
				puts("\nmalloc");
				j->next = malloc(sizeof(t_job));
				j = j->next;
				init_job(j);
			}
		}
		if (res[i])
			i++;
	}
	j->next = NULL;
}

int			start_exec(t_lexeur **res)
{
	t_job		*j;

	j = malloc(sizeof(t_job));
	init_job(j);
	fill_job(j, res);
	fill_process(j, res);
	print_job(j);
	return (0);
}
