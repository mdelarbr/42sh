/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 04:04:12 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 12:08:31 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"

void	ft_free_struct(void)
{
	t_ft *ft;

	ft = ft_getstruct(NULL);
	if (ft)
	{
		if (ft->env)
			ft_free_var_list(&(ft->env));
		if (ft->his)
			ft_free_list(&(ft->his));
		free(ft);
		ft = NULL;
	}
}
