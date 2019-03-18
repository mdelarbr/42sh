/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_exec_verbose.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 15:52:42 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 16:28:10 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "execute.h"

int		ft_is_exec_verbose(char *str)
{
	if (ft_file_exists(str))
	{
		if (ft_file_xrights(str))
			return (1);
		ft_putstr(str);
		ft_putstr(": can't be executed, permission denied\n");
	}
	return (0);
}
