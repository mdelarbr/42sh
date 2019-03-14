/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 03:30:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 09:11:58 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

#include "stdio.h"

void	ft_error(int nb)
{
	if (nb == 1)
	{
		ft_putstr("an error occured at the begining,");
		ft_putstr("very worrisome, anyway ... \n");
	}
	if (nb == 2)
	{

	}
	ft_putstr("quitting with class \n");
	ft_free_struct();
	exit(0);
}
