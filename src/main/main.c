/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:32:39 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 10:17:01 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static void		exit_mode(t_pos *pos, t_hist *hist)
{
	free(pos->prompt);
	free_t_hist(hist);
	free(pos->ans);
	close(pos->history);
	tcsetattr(2, TCSANOW, &(pos->old_term));
	exit(0);
}

int				main(int ac, char **av, char **env)
{
	char	*ans;
	t_hist	*hist;
	t_var	*my_env;
	t_pos	pos;

	(void)ac;
	(void)av;
	my_env = init_env(env);
	stock(my_env, 5);
	hist = (t_hist *)malloc(sizeof(t_hist));
	init_t_hist(hist);
	pos.is_complete = 1;
	pos.prompt = NULL;
	hist = create_history(&pos, hist);
	ghist = &hist;
	while (1)
	{
		ans = termcaps42sh(&pos, hist);
		if (ans == NULL)
			break ;
		if (ans && ft_strcmp("exit", ans) == 0)
			exit_mode(&pos, hist);
		if (pos.error == 1)
			error_handling(&pos, NULL, 0);
		if ((check_error(ans)) != -1)
			start_exec(start_lex(my_env, ans), my_env);
		else
			pos.ans = ft_secure_free(pos.ans);
		pos.error = 0;
	}
}
