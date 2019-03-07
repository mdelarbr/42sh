/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 12:29:29 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 18:15:47 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (0);
	i = 0;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) *
					(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1))))
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	ft_strdel(&s1);
	return (dest);
}
