/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/03 14:47:50 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/03 16:59:16 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_int.h"

static void	ft_putstr(const char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

static char	ft_inttochar(int i)
{
	if (i < 10)
		return (i + 48);
	else
		return ('A' + i - 10);
}

static int	ft_intlen_base(int n, int base)
{
	if (n < 0)
	{
		if (n / base)
			return (2 + ft_intlen_base(-(n / base), base));
		else
			return (1 + ft_intlen_base((n / base), base));
	}
	else if (n < base)
		return (1);
	return (1 + ft_intlen_base(n / base, base));
}

static char	*ft_itoa_base(int nb, int base)
{
	char	*r;
	int		j;
	long	n;

	j = ft_intlen_base(nb, base);
	if (!(r = malloc(sizeof(*r) * (j + 1))))
		return (NULL);
	r[j--] = '\0';
	n = nb;
	if (nb < 0)
		n = n * -1;
	while (j >= 0)
	{
		r[j] = ft_inttochar(n % base);
		n = n / base;
		j--;
	}
	if (nb < 0)
		r[0] = '-';
	return (r);
}

void		ft_putnbr_base(int nb, int base)
{
	if (base <= 1)
		return ;
	ft_putstr(ft_itoa_base(nb, base));
}
