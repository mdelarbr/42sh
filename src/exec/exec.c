/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:43:41 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/24 11:39:51 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/lexeur.h"

/*
** completer t_job->t_process->cmd jusqu'a un token ou la fin de la str.
** Si on trouve un token alors on remplie t_job->t_process->next. (le char **
** est la parce que execve en prend un).
** Faire un split de jobs si on rencontre ; ou &.
** On verrq les pid_t plus tard.
** t_process->completed/stopped sont la pour savoir l'etat du process et meme
** principe pour les jobs.
*/

int		start_exec(t_lexeur **res)
{
	int			i;
	int			k;
	t_job		*j;

	j = malloc(sizeof(t_job));
	j->p = malloc(sizeof(t_process));
	i = 0;
	k = 0;
	while (res[i])
	{
		printf("res[%d].word: {%s}\tres[%d].token: {%d}\tres[%d].redirection:{%s}\tfd: %d\n", i, res[i]->word, i, res[i]->token, i, res[i]->redirection, res[i]->fd);
		if (res[i]->word)
		{
			j->p->cmd = malloc(sizeof(char*) * 2); //attention
			j->p->cmd[k] = ft_strdup(res[i]->word);
			printf("j->p->cmd[%d]: _%s_\n", k, j->p->cmd[k]);
			k++;
		}
		if (!res[i]->word)
			k = 0;
		i++;
	}
	return (0);
}