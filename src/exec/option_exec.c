/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option_exec.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 15:35:45 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 11:15:44 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"

int		exec_and(t_process **first, t_process **second, t_var *var)
{
	while (1)
	{
		if (main_exec_while((*first), var) != 0)
			return (-1);
		if (!(*second))
			break ;
		main_exec_while((*second), var);
		if ((*second)->split == 'A')
		{
			(*first) = (*second)->next;
			(*second) = (*second)->next->next;
		}
		else
		{
			(*first) = (*first)->next;
			break ;
		}
	}
	return (1);
}

int		main_option_exec(t_process **first, t_process **second, t_var *var)
{
	if ((*first)->split == 'A')
		return (exec_and(first, second, var));
	/*if (first->split == 'P')
		exec_pipe(first, second, var);
	if (first->split == '|')
		exec_or();*/
	return (1);
}