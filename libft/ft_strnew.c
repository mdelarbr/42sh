/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:18:17 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 17:04:07 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if (!(new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (size--)
	{
		new[i++] = '\0';
	}
	new[i] = '\0';
	return (new);
}
