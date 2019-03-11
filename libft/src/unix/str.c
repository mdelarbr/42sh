/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:42:47 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 16:15:01 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unix.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	if (!(ret = malloc(sizeof(ret) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
