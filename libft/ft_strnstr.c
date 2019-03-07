/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:07:48 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 17:34:34 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, int n)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while ((str[i] != '\0') && (n != i))
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			j++;
			if (to_find[j] == '\0')
				return ((char*)str + i);
			if ((i + j == n))
				return (0);
		}
		i++;
	}
	return (0);
}
