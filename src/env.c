/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 04:20:29 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 14:09:10 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

int		ft_get_env(char **env, t_var **var)
{
	char		**tab;
	int			i;
	t_var		*new;

	i = 0;
	while (env[i])
	{
		tab = ft_strsplit(env[i], '=');
		new = create_var_str_elem(tab[0], tab[1]);
		new->type = 0;
		ft_add_var_elem(var, new);
		i++;
		ft_free_tab(tab);
		tab = NULL;
	}
	return (i);
}
