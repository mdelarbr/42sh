/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 16:41:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/16 12:06:32 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

void	read_history(t_ft *ft);

void	get_history(t_ft *ft)
{
	if (ft_file_exists(".42_history"))
	{
		if (ft_file_rrights(".42_history") && ft_file_wrights(".42_history"))
		{
		}
		else
			ft_error(2);
	}
	else
	{
		if (ft_create_file(".42_history"))
			ft_error(-2);
		else
			ft_error(2);
	}
}
