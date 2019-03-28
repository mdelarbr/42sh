/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:45:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 09:34:56 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

int		get_term(void)
{
	int		ret;
	char	*name;

	ret = 0;
	name = getenv("TERM");
	if (name == NULL)
	{
		ft_putstr("TERM unset, please set it\n");
		return (0);
	}
	ret = tgetent(NULL, name);
	if (ret == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ret == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

void	free_env(t_env *var)
{
	t_env *tmp;

	tmp = var;
	while (var)
	{
		ft_strdel(&var->name);
		ft_strdel(&var->data);
		var = var->next;
		free(tmp);
		tmp = var;
	}
}

void	free_all(t_all *all)
{
	t_history	*save;

	free_env(all->env);
	free(all->wind);
	while (all->history && all->history->prev)
		all->history = all->history->prev;
	while (all->history && HNEXT)
	{
		save = all->history;
		free(CMD);
//		free(HPREV);
		all->history = HNEXT;
		free(save);
	}
	free(all->history);
	free(all);
}

int		main(int ac, char **av, char **env)
{
	t_select	*select;
	t_history	*history;
	t_all		*all;
	char		*res;

	(void)ac;
	(void)av;
	all = malloc(sizeof(t_all));
	history = NULL;
	get_history(&history);
	while (history->next)
		history = history->next;
	select = NULL;
	all->env = init_env(env);
	all->history = history;
	if (get_term() == -1)
		return (0);
	if (isatty(2) == 0)
		return (0);
	select = init_term(select);
	all->wind = init_wind();
	all->last = all->history;
	while (1)
	{
		tputs(tgetstr("ve", NULL), 1, ft_put_c);
		res = key_hook(all);
		ft_putcolor("\n", res, "\n");
		if (ft_strcmp("exit", res) == 0)
		{
			while (all->last->next != NULL)
				all->last = all->last->next;
			if (all->last->next == NULL)
			{
				all->last->next = malloc(sizeof(t_history));
				all->last = all->last->next;
				all->last->cmd = ft_strdup(res);
			}
			ft_strdel(&res);
			break ;
		}
	}
	tcsetattr(2, TCSANOW, &(OTERM));
	tputs(tgetstr("ve", NULL), 1, ft_put_c);
	free(select);
//	free_all(all);
//	free(history);
	return (0);
}
