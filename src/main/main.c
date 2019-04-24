/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 11:17:48 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/24 11:37:07 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../includes/lexeur.h"
#include "../../includes/exec.h"
#include "../../includes/check_error.h"

int		main(int ac, char **av, char **env)
{
	t_all		*all;

	(void)ac;
	(void)av;
	all = NULL;
	all = init_all(all, env);
	if (check_term() == -1)
		return (0);
	while (all->last->next)
		all->last = all->last->next;
	while (1)
	{
		if (main_line_edit(all) == 0)
			break ;
		if ((check_error(all->last->cmd)) != -1)
			start_exec(start_lex(all));
		ft_strdel(&all->save);
	}
	end_of_shell(all);
	return (0);
}