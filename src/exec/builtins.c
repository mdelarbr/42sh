/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 11:06:30 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:10:24 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"

/*
** TODO faire en sorte qu'on puisse exec un builtins au milieu d'autres
** comme ls.
*/

int		find_builtins(t_process *p)
{
	if (ft_strcmp(p->cmd[0], "cd") == 0)
		return (1);
	return (0);
}
