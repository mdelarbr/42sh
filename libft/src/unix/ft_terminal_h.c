/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_terminal_h.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 23:24:43 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 09:22:54 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_unix.h"

int		ft_terminal_h(int fd)
{
	struct winsize	w;

	ioctl(fd, TIOCGWINSZ, &w);
	return (w.ws_row);
}
