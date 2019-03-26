/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 12:52:18 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 12:52:29 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtin.h"

void		add_list_env(t_ft *global, char *name, char *env)
{
	t_var *next;

	next = global->env;
	if (global->env == NULL)
	{
		global->env = create_var_str_elem(ft_strdup(name), ft_strdup(env));
		return ;
	}
	while (next != NULL)
	{
		if (ft_strcmp(name, next->var) == 0)
		{
			free(next->val);
			next->val = ft_strdup(env);
			return ;
		}
		if (next->next == NULL)
		{
			next->next = create_var_str_elem(ft_strdup(name), ft_strdup(env));
			return ;
		}
		next = next->next;
	}
	return ;
}
