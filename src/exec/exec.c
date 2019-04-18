/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:43:41 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 16:58:58 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/lexeur.h"

int		start_exec(t_lexeur **res)
{
	int		j;

	j = 0;
	while (res[j])
	{
		printf("res[%d].word: {%s}\tres[%d].token: {%d}\tres[%d].redirection:{%s}\tfd: %d\n", j, res[j]->word, j, res[j]->token, j, res[j]->redirection, res[j]->fd);
		j++;
	}
	return (0);
}