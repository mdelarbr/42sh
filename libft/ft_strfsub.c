/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 14:09:36 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 18:15:27 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!(s))
		return (0);
	i = start;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	j = 0;
	while (j < len)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	ft_strdel(&s);
	return (dest);
}
