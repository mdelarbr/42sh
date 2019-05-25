/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:32:39 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/25 15:06:09 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int			main(int ac, char **av, char **env)
{
	char	*ans;
	t_hist	*hist;
	t_var	*my_env;
	t_pos	pos;

	(void)ac;
	(void)av;
	hist = (t_hist *)malloc(sizeof(t_hist));
	init_t_hist(hist);
	my_env = init_env(env);
	pos.prompt = NULL;
	pos.is_complete = 1;
	hist = create_history(&pos, hist);
	while (1)
	{
		ans = termcaps42sh("$ ", 0, &pos, hist);
		if (ans == NULL)
			break ;
		if (ft_strcmp("exit", ans) == 0)
		{
			free(pos.prompt);
			close(pos.history);
			free_t_hist(hist);
			tcsetattr(2, TCSANOW, &(pos.old_term));
			free_env(my_env);
			return (0);
		}
		if ((check_error(ans)) != -1)
			start_exec(start_lex(my_env, ans), my_env);
	}
}
