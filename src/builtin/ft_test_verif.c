/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_verif.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/14 15:52:42 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 15:53:14 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtin.h"

int			verif_int(char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if ((i == 0 && name[i] == '-') ||
			(name[i] >= '0' && name[i] <= '9'))
			i++;
		else
		{
			ft_printf("test: integer expression expected: %s\n", name);
			return (-1);
		}
	}
	return (0);
}
