/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 03:30:24 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 16:56:27 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

#include "stdio.h"

void	ft_error(int nb)
{
	if (nb < 0)
	{
		nb == -1 ? ft_putstr("/!\\launching with an empty environement\n") : 0;
		nb == -2 ? ft_putstr("file .42_history created to save history\n") : 0;
		nb == -3 ? ft_putstr("file .42_alias created to save alias\n") : 0;
	}
	else
	{
		nb == 0 ? ft_putstr("an error occured at the begining,") : 0;
		nb == 0 ? ft_putstr("very worrisome, anyway ... \n") : 0;
		nb == 2 ? ft_putstr("couldn't create .42_history (no mkdir ?) ") : 0;
		nb == 2 ? ft_putstr("or don't have rights on it...\nsad but...\n") : 0;
		nb == 3 ? ft_putstr("couldn't create .42_alias (no mkdir ?) ") : 0;
		nb == 3 ? ft_putstr("or don't have rights on it...\nsad but...\n") : 0;
		ft_putstr("quitting with class ;)\n");
		ft_free_struct();
		exit(0);
	}
}