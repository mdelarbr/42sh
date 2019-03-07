/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:41:22 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 12:16:15 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int i;

	i = 0;
	if (src > dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			((char *)dest)[n] = ((char*)src)[n];
	}
	return (dest);
}
