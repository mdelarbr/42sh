/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alias.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 16:36:57 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 17:02:17 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

void	read_alias(t_var **var);

void	get_alias(t_var **var)
{
	if (ft_file_exists(".42_alias"))
	{
		if (ft_file_rrights(".42_alias") && ft_file_wrights(".42_alias"))
		{
		}
		else
			ft_error(3);
	}
	else
	{
		if (ft_create_file(".42_alias"))
			ft_error(-3);
		else
			ft_error(3);
	}
}
