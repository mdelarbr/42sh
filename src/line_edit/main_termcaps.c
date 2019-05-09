/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_termcaps.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:32:39 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 10:33:36 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int		main(int ac, char **av, char **env)
{
	char	*ans;
	t_hist	*hist;
	t_pos	pos;
	t_var	*var;

	(void)ac;
	(void)av;
	var = init_env(env);
	hist = (t_hist *)malloc(sizeof(t_hist));
	init_t_hist(hist);
	pos.prompt = NULL;
	pos.is_complete = 1;
	hist = create_history(&pos, hist);
	while (1)
	{
		ans = termcaps42sh("$ ", &pos, hist);
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
		ans = ft_secure_free(ans);
	}
}
