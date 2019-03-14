/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_shell.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 21:38:56 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 03:16:12 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

void	ft_print_shell_a(int w)
{
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████████████████████████████████████████");
	ft_putstr("\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████████████\033[38;5;0mhusahuc ");
	ft_putstr("\033[38;5;33m████████████████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████████\033[38;5;0m████");
	ft_putstr("\033[38;5;2m████████\033[38;5;0m████");
	ft_putstr("\033[38;5;33m████████████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████\033[38;5;0m████");
	ft_putstr("\033[38;5;2m████████████████\033[38;5;0m████");
	ft_putstr("\033[38;5;33m████████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██████████\033[38;5;0m██\033[38;5;2m██");
	ft_putstr("\033[38;5;0m██\033[38;5;2m██████████\033[38;5;15m████");
	ft_putstr("\033[38;5;2m██\033[38;5;0m██\033[38;5;2m██\033[38;5;0m██");
	ft_putstr("\033[38;5;33m██████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████\033[38;5;0m██\033[38;5;2m██████");
	ft_putstr("\033[38;5;0m██\033[38;5;2m████████████\033[38;5;0m██");
	ft_putstr("\033[38;5;2m██████\033[38;5;0m██\033[38;5;33m████████\n");
	ft_put_space(w);
}

void	ft_print_shell_b(int w)
{
	ft_putstr("\033[38;5;33m████████\033[38;5;0m██\033[38;5;2m██████");
	ft_putstr("\033[38;5;112m██\033[38;5;0m mdelarbr ;)\033[38;5;2m████████");
	ft_putstr("\033[38;5;0m██\033[38;5;33m████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██████\033[38;5;0m██\033[38;5;2m████████");
	ft_putstr("\033[38;5;0m██\033[38;5;112m████████\033[38;5;2m████");
	ft_putstr("\033[38;5;0m██\033[38;5;2m████████\033[38;5;0m██");
	ft_putstr("\033[38;5;33m██████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██████\033[38;5;0m██\033[38;5;2m██████");
	ft_putstr("\033[38;5;0m██\033[38;5;112m██████████\033[38;5;2m██████");
	ft_putstr("\033[38;5;0m██\033[38;5;2m██████\033[38;5;0m██");
	ft_putstr("\033[38;5;33m██████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██████\033[38;5;0m██\033[38;5;2m████");
	ft_putstr("\033[38;5;0m██\033[38;5;112m████████████\033[38;5;2m██████");
	ft_putstr("\033[38;5;112m██\033[38;5;0m██\033[38;5;2m████\033[38;5;0m██");
	ft_putstr("\033[38;5;33m██████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████\033[38;5;0m██\033[38;5;2m████\033[38;5;0m██");
	ft_putstr("\033[38;5;112m██\033[38;5;2m██\033[38;5;112m██████████");
	ft_putstr("\033[38;5;2m████████\033[38;5;112m██\033[38;5;0m██");
	ft_putstr("\033[38;5;2m████\033[38;5;0m██\033[38;5;33m████\n");
	ft_put_space(w);
}

void	ft_print_shell_c(int w)
{
	ft_putstr("\033[38;5;33m████\033[38;5;0m██\033[38;5;2m██");
	ft_putstr("\033[38;5;0m██\033[38;5;2m██\033[38;5;0m██\033[38;5;2m████");
	ft_putstr("\033[38;5;112m██████\033[38;5;2m██████████\033[38;5;0m██");
	ft_putstr("\033[38;5;2m██\033[38;5;0m██\033[38;5;2m██\033[38;5;0m██");
	ft_putstr("\033[38;5;33m████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████\033[38;5;0m████████\033[38;5;2m██");
	ft_putstr("\033[38;5;0m██\033[38;5;2m████████████████\033[38;5;0m██");
	ft_putstr("\033[38;5;2m██\033[38;5;112m████\033[38;5;0m████");
	ft_putstr("\033[38;5;33m████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██\033[38;5;0m████\033[38;5;2m██████████");
	ft_putstr("\033[38;5;0m██\033[38;5;2m████████████\033[38;5;0m██");
	ft_putstr("\033[38;5;2m██████████\033[38;5;0m████\033[38;5;33m██\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██\033[38;5;0m██\033[38;5;15m██");
	ft_putstr("\033[38;5;2m████████████\033[38;5;0m mjalenqu :D");
	ft_putstr("\033[38;5;112m██\033[38;5;2m████████\033[38;5;0m██");
	ft_putstr("\033[38;5;15m██\033[38;5;0m██\033[38;5;33m██\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██\033[38;5;0m██\033[38;5;15m██");
	ft_putstr("\033[38;5;0m██\033[38;5;2m████████\033[38;5;0m██");
	ft_putstr("\033[38;5;2m████████████\033[38;5;0m██");
	ft_putstr("\033[38;5;2m████████\033[38;5;0m██\033[38;5;15m██");
	ft_putstr("\033[38;5;0m██\033[38;5;33m██\n");
}

void	ft_print_shell_d(int w)
{
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██\033[38;5;0m██\033[38;5;248m██");
	ft_putstr("\033[38;5;15m██\033[38;5;0m████\033[38;5;2m██\033[38;5;0m██");
	ft_putstr("\033[38;5;2m████████████████\033[38;5;0m██\033[38;5;2m██");
	ft_putstr("\033[38;5;0m████\033[38;5;15m██\033[38;5;248m██");
	ft_putstr("\033[38;5;0m██\033[38;5;33m██\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████\033[38;5;0m██\033[38;5;15m██████");
	ft_putstr("\033[38;5;0m████\033[38;5;2m████████████████");
	ft_putstr("\033[38;5;0m████\033[38;5;15m██████\033[38;5;0m██");
	ft_putstr("\033[38;5;33m████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████\033[38;5;0m██\033[38;5;248m██");
	ft_putstr("\033[38;5;15m████████\033[38;5;0m    shthevak =D ");
	ft_putstr("\033[38;5;15m████████\033[38;5;248m██\033[38;5;0m██");
	ft_putstr("\033[38;5;33m████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m██████\033[38;5;0m██\033[38;5;248m████");
	ft_putstr("\033[38;5;15m████████████████████████\033[38;5;248m████");
	ft_putstr("\033[38;5;0m██\033[38;5;33m██████\n");
	ft_put_space(w);
}

void	ft_print_shell_e(int w)
{
	ft_putstr("\033[38;5;33m████████\033[38;5;0m████\033[38;5;248m████");
	ft_putstr("\033[38;5;15m████████████████\033[38;5;248m████");
	ft_putstr("\033[38;5;0m████\033[38;5;33m████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████\033[38;5;0m████");
	ft_putstr("\033[38;5;248m████████████████\033[38;5;0m████");
	ft_putstr("\033[38;5;33m████████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████████\033[38;5;0m████████████████");
	ft_putstr("\033[38;5;33m████████████████\n");
	ft_put_space(w);
	ft_putstr("\033[38;5;33m████████████████████████████████████████████████");
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\033[0m");
}
