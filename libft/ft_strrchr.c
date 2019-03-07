/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 20:15:05 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 16:45:16 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[len]);
	while (len--)
	{
		if (str[len] == c)
			return ((char *)&str[len]);
	}
	return (0);
}
