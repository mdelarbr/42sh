/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   restart.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:07:29 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 11:01:41 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			print_history(t_all *all)
{
	t_history *save;

	save = all->last;
	while (save->prev)
	{
		printf("/ %s /\n", save->cmd);
		save = save->prev;
	}
	printf("/ %s /\n", save->cmd);
}

int				check_key(t_all **all, long key)
{
	if (key == UP)
		go_up();
	else if (key == DOWN)
		go_down();
	else if (key == LEFT)
		go_left();
	else if (key == RIGHT)
		go_right();
	else if (key == ENTER)
		return (-1);
	else if (key == BACK)
		do_backspace();
	else
		return (0);
	return (1);
}

int				check_enter(t_all *all)
{
	int i;

	i = 0;
	while (all->cur->res )
}

void			loop_read(t_all *all)
{
	long	key;

	key = 0;
	while (read(0, &key, 8) > -1)
	{
		if (check_key(&all, key) == -1)
			if (check_enter(all) == -1)
				break ;
	}
}

static t_all	*init_all(t_all *all, char **env)
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
	all->prompt = ft_strdup("prompt->");
	all->cur = malloc(sizeof(t_command));
	all->cur->prev = NULL;
	all->cur->next = NULL;
	all->cur->res = NULL;
	return (all);
}

static void		end_of_shell(t_all *all)
{
	tcsetattr(2, TCSANOW, &(all->select->old_term));
	tputs(tgetstr("ve", NULL), 1, ft_put_c);
	write_history(all);
	free(all->select);
}

int				main(int ac, char **av, char **env)
{
	t_all *all;

	all = NULL;
	all = init_all(all, env);
	if (check_term() == -1)
		return (0);
	while (1)
	{
		loop_read(all);
		ft_putcolor("\n\033[0;32m", all->last->cmd, "\033[00m\n");
		if (ft_strcmp(all->last->cmd, "hist") == 0)
			print_history(all);
		if (ft_strcmp("exit", all->last->cmd) == 0)
			break ;
	}
	end_of_shell(all);
	return (0);
}