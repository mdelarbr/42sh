/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove_c.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 15:47:43 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 10:10:53 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmvi(char *str, int i)
{
	char	*ret;

	ret = NULL;
	if (i < 0)
		ret = ft_strdup(str);
	else
	{
		ret = ft_strsub(str, 0, i);
		if (i + 1 < ft_strlen((const char *)str))
			ret = ft_strfjoin(ret, str + i + 1);
	}
//	if (str)
//		ft_strdel(&str);
	return (ret);
}
