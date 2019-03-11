/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/09 13:39:29 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 16:14:51 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_int.h"

#include <signal.h>

int main(int a, char **b)
{
	char	*str = ft_strdup("te st");
	char *ret;

	ret = ft_strrmvi(str, 2);
	ft_putstr(ret);
	free(ret);
	ft_putstr("\n\n");
	str = ft_strdup("te st");
	ret = ft_strrmvi(str, 0);
	ft_putstr(ret);
	free(ret);
	ft_putstr("\n\n");
	str = ft_strdup("te st");
	ret = ft_strrmvi(str, 5);
	ft_putstr(ret);
	free(ret);
	ft_putstr("\n\n");
	str = ft_strdup("te st");
	ret = ft_strrmvi(str, 4);
	ft_putstr(ret);
	free(ret);
	ft_putstr("\n\n");
	return (0);
}
