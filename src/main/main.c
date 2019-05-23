/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:32:39 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 11:29:17 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int		main(int ac, char **av, char **env)
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
		if (ft_strcmp("exit", ans) == 0)
		{
			free(pos.prompt);
			free_t_hist(hist);
			free(ans);
			close(pos.history);
			tcsetattr(2, TCSANOW, &(pos.old_term));
			exit(0);
		}
		if ((check_error(ans)) != -1)
			start_exec(start_lex(my_env, ans), my_env);
//		ans = ft_secure_free(ans);
	}
}
