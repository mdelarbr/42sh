/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 16:10:34 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 09:34:11 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int ac, char **av)
{
	int i = 1;
	(void)ac;
	char *str;
	char *tmp;

	tmp = ft_strdup(av[1]);
	str = ft_strrmvi(tmp, i);
	ft_putcolor("-->", str, "\n");
	return (0);
}
