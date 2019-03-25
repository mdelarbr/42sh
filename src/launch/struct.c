/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <shthevak@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 02:36:51 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 16:00:08 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"

t_var		*init_list_env(char **env)
{
	int		i;
	t_var	*start;
	t_var	*next;
	char	**env_char;

	if (env == NULL || env[0] == NULL)
		return (NULL);
	env_char = ft_strsplit(env[0], '=');
	if ((start = create_var_str_elem(env_char[0], env_char[1])) == NULL)
		return (NULL);
	free(env_char);
	next = start;
	i = 1;
	while (env[i] != NULL)
	{
		env_char = ft_strsplit(env[i], '=');
		if ((next->next = create_var_str_elem(env_char[0], env_char[1])) == NULL)
			return (NULL);
		next = next->next;
		free(env_char);
		i++;
	}
	return (start);
}

t_ft	*ft_getstruct(char **env)
{
	static t_ft	*ft = NULL;
	t_var		*env_ptr;

	if (ft == NULL)
	{
		if (!(ft = malloc(sizeof(t_ft))))
			return (NULL);
		ft->env = init_list_env(env);
		ft->his = NULL;
		ft->fd_his = -1;
		ft->fd_alias = -1;
		get_history(ft);
		get_alias(ft);
	}
	return (ft);
}
