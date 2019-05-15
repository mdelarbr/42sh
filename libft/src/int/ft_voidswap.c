/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_voidswap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/03 15:05:36 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 09:22:54 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_voidswap(void *s, void *d)
{
	unsigned char	c;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s;
	b = (unsigned char *)d;
	c = *a;
	*a = *b;
	*b = c;
}
