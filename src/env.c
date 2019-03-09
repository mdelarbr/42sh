/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/08 10:53:46 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 13:10:38 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	print_env(t_env *var)
{
	while (var)
	{
		ft_putcolor2(var->name, "=", var->data, "\n");
		var = var->next;
	}
}

char	*init_data(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] && src[i] != '=')
		i++;
	i++;
	dest = ft_strsub(src, i, ft_strlen(src) - i);
	return (dest);
}

char	*init_name(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] && src[i] != '=')
		i++;
	dest = ft_strsub(src, 0, i);
	return (dest);
}

t_env	*init_env(char **env)
{
	t_env	*var;
	t_env	*save;
	int		i;

	i = 0;
	var = malloc(sizeof(t_env));
	save = var;
	while (env[i])
	{
		var->name = init_name(env[i]);
		var->data = init_data(env[i]);
		i++;
		if (env[i])
		{
			var->next = malloc(sizeof(t_env));
			var = var->next;
		}
	}
	var->next = NULL;
//	print_env(save);
	return (save);
}
