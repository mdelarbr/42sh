/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 02:36:51 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 16:56:46 by shthevak    ###    #+. /#+    ###.fr     */
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
		ft->his = NULL;
		ft->fd_his = -1;
		ft->fd_alias = -1;
		ft->env_nb = ft_get_env(env, &(ft->env));
		ft->env == NULL ? ft_error(-1) : 0;
		get_history(&(ft->his));
		get_alias(&(ft->env));
	}
	return (ft);
}
