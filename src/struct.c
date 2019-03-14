/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 02:36:51 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 09:05:08 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

t_ft	*ft_getstruct(char **env)
{
	static t_ft *ft = NULL;

	if (ft == NULL)
	{
		if (!(ft = malloc(sizeof(t_ft))))
			return (NULL);
		ft->env = NULL;
		ft->env_nb = ft_get_env(env, &(ft->env));
		ft->his = NULL;
		ft->fd_his = -1;
		ft->fd_alias = -1;
	}
	return (ft);
}
