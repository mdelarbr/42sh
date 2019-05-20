/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 15:00:57 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/16 15:12:54 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/exec.h"

int		ft_echo(t_process *p, t_var **var)
{
	int i;

	i = 1;
	var = NULL;
	while (p->cmd[i] != NULL)
	{
		if (i != 1)
			ft_putchar(' ');
		ft_putstr(p->cmd[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
