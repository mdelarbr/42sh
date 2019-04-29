/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_termcaps.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 14:32:39 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 11:19:26 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int		main_line_edit(void)
{
	char	*ans;
	t_hist	*hist;
	t_pos	pos;
	
	hist = (t_hist *)malloc(sizeof(t_hist));
	init_t_hist(hist);
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
			free_t_hist(hist);
			free(ans);
			close(pos.history);
			exit(0);
		}
	//	ft_printf("reponse -> /%s/\n", ans);
		ft_strdel(&ans);
	}
	return (0);
}
