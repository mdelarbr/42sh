/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 12:27:38 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 16:23:28 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long	nb;
	int		i;
	int		neg;

	nb = 0;
	i = 0;
	neg = 0;
	while (str[i] == '\f' || str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		nb = -nb;
	return ((int)nb);
}
