/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 15:00:57 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 11:38:07 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtin.h"

int		ft_echo(char *argv[], t_ft *global)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (i != 1)
			ft_putchar(' ');
		ft_putstr(argv[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
