/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_int.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 10:10:59 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 10:14:42 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/builtin.h"

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
			printf("test: integer expression expected: %s\n", name);
			return (-1);
		}
	}
	return (0);
}

int			comp_num_operator(char *name1, char *type, char *name2)
{
	if (verif_int(name1) == -1 || verif_int(name2) == -1)
		return (2);
	if (ft_strcmp(type, "-eq") == 0)
		return (ft_atoi(name1) == ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-ne") == 0)
		return (ft_atoi(name1) != ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-ge") == 0)
		return (ft_atoi(name1) >= ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-lt") == 0)
		return (ft_atoi(name1) < ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-le") == 0)
		return (ft_atoi(name1) <= ft_atoi(name2)) ? 0 : 1;
	else
	{
		printf("test: unknown condition: %s\n", type);
		return (2);
	}
}
