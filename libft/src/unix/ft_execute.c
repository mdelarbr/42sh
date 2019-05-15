/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_execute.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 15:32:21 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 09:22:54 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_unix.h"

int	ft_execute(char *exec, char **opt, char **env)
{
	int		w;
	pid_t	p;

	p = fork();
	if (p == 0)
	{
		if (execve(exec, opt, env) == -1)
			return (0);
	}
	else
		wait(&w);
	return (1);
}
