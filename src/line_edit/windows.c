/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   windows.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 23:04:55 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 09:27:25 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_wind	init_wind(void)
{
	struct winsize	w;
	t_wind			wind;
	char			buf[42];
	int				i;

	i = 0;
	ioctl(2, TIOCGWINSZ, &w);
	wind.max_col = w.ws_col;
	wind.max_line = w.ws_row;
	write(2, "\033[6n", 4);
	read(2, buf, 38);
	buf[38] = '\0';
	wind.pos_line = ft_atoi(buf + 2) - 1;
	while (buf[i] && buf[i] != ';')
		i++;
	wind.pos_col = ft_atoi(buf + i + 1);
	tputs(tgetstr("dl", NULL), 0, ft_put_c);
	return (wind);
}
