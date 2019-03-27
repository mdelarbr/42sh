/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:03:24 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 16:00:47 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank_nl(int c)
{
	if (ft_isblank(c) || c == '\n')
		return (1);
	return (0);
}

static void	gain_place(int j, int i, char *dest, char *s)
{
	int len;

	len = i;
	i = 0;
	while (len <= j)
	{
		dest[i] = s[len];
		i++;
		len++;
	}
	dest[i] = '\0';
}

char		*ft_strtrim(char const *s)
{
	char	*dest;
	int		i;
	int		j;

	if (!(s))
		return (0);
	i = 0;
	j = (ft_strlen((char*)s) - 1);
	while (ft_isblank_nl(s[i]) == 1)
		i++;
	while (ft_isblank_nl(s[j]) == 1 && i < j)
		j--;
	if (!(dest = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (0);
	if (i == 0 && j == ft_strlen((char*)s - 1))
		dest = (char*)s;
	else
		gain_place(j, i, dest, (char*)s);
	return (dest);
}
