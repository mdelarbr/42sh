/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:45:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 13:33:14 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	print_history(t_all *all)
{
	t_history *save;

	save = all->last;
	while (save->prev)
	{
		ft_putendl(save->cmd);
		save = save->prev;
	}
	ft_putendl(save->cmd);
}

t_all	*init_all(t_all *all, char **env)
{
	all = malloc(sizeof(t_all));
	get_history(&all->history);
	while (all->history->next)
		all->history = all->history->next;
	all->select = NULL;
	all->select = init_term(all);
	all->env = init_env(env);
	all->wind = init_wind();
	all->last = all->history;
	all->up = 0;
	all->tmp = NULL;
	return (all);
}

void	end_of_shell(t_all *all)
{
	tcsetattr(2, TCSANOW, &(OTERM));
	tputs(tgetstr("ve", NULL), 1, ft_put_c);
	free(all->select);
}

void	add_res(char *res, t_all *all)
{
	while (all->last->next != NULL)
		all->last = all->last->next;
	if (all->last->next == NULL)
	{
		all->last->next = malloc(sizeof(t_history));
		all->last->next->prev = all->last;
		all->last = all->last->next;
		all->last->cmd = ft_strdup(res);
		all->last->next = NULL;
	}
	all->history = all->last;
}

int		main(int ac, char **av, char **env)
{
	t_all		*all;
	char		*res;

	(void)ac;
	(void)av;
	all = NULL;
	all = init_all(all, env);
	if (check_term() == -1)
		return (0);
	while (1)
	{
		all->up = 0;
		tputs(tgetstr("ve", NULL), 1, ft_put_c);
		res = key_hook(all);
		ft_putcolor("\n\033[0;32m", res, "\033[00m\n");
		add_res(res, all);
		if (ft_strcmp(res, "hist") == 0)
			print_history(all);
		if (ft_strcmp("exit", res) == 0)
		{
			ft_strdel(&res);
			break ;
		}
	}
	end_of_shell(all);
	return (0);
}
