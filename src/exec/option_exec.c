/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option_exec.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:35:45 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:10:18 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	exec_and(t_process *first, t_process *second, t_var *var)
{
	if (main_exec_while(first, var) == 0)
		main_exec_while(second, var);
	(*first) = (*second);
}

int		main_option_exec(t_process **first, t_process **second, t_var *var)
{
	if ((*first)->split == 'A')
	{
		exec_and((*first), (*second), var);
		if ((*second) && ((*second)->next) && (*second)->split == 'A')
			(*second)->next->split = 'A';
	}
	/*if (first->split == 'P')
		exec_pipe(first, second, var);
	if (first->split == '|')
		exec_or();*/
	return (1);
}
