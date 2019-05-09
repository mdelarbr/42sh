/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 10:52:26 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 11:07:53 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"

int			cnt_size(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			i++;
		if (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
		{
			nb++;
			while (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
				i++;
		}
	}
	return (nb);
}

char		**split_space(char *str)
{
	int		i;
	int		k;
	char	**res;
	int		start;

	i = 0;
	k = 0;
	res = malloc(sizeof(char *) * (cnt_size(str) + 1));
	while (str[i])
	{
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			i++;
		if (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
		{
			start = i;
			while (str[i] && ((str[i] < 9 || str[i] > 13) && str[i] != ' '))
				i++;
			res[k] = ft_strsub(str, start, i - start);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}
