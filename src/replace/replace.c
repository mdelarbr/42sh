/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 17:27:56 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 16:25:10 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lexeur.h"
#include "../../includes/termcaps.h"

char		*env_var(t_var *env, char *str)
{
	t_var	*start;

	start = env;
	while (start)
	{
		if (ft_strcmp(start->name, str) == 0 && start->type == ENVIRONEMENT)
		{
			ft_strdel(&str);
			return (start->data);
		}
		start = start->next;
	}
	ft_strdel(&str);
	return (ft_strdup(""));
}

char		*make_string(char **array)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup("");
	while (array[i])
	{
		ft_strjoin_free(&res, array[i]);
		if (array[i + 1])
			ft_strjoin_free(&res, " ");
		i++;
	}
	return (res);
}

char		*replace_alias(char *array, t_var *var, t_replace *replace)
{
	int			i;
	char		*res;
	t_replace	*tmp;

	tmp = replace;
	i = 0;
	while (var && (ft_strcmp(array, var->name) != 0 && var->type != ALIAS))
		var = var->next;
	if (!var)
	{
		res = ft_strdup(array);
		ft_strdel(&array);
		return (res);
	}
	while (tmp)
	{
		if (ft_strcmp(tmp->name, var->name) == 0)
		{
			res = ft_strdup(var->name);
			ft_strdel(&array);
			return (res);
		}
		tmp = tmp->next;
	}
	list_add(&replace, array);
	res = ft_strdup(var->data);
	ft_strdel(&array);
	return (res);
}

int			check_alias(char *array, t_var *var, t_replace *replace)
{
	int			i;
	t_replace	*tmp;

	i = 0;
	tmp = replace;
	while (var && (ft_strcmp(array, var->name) != 0 && var->type != ALIAS))
		var = var->next;
	if (!var)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, var->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			remove_env_while(char ***array, t_var *var, t_replace *replace)
{
	int		done;
	int		i;

	done = 0;
	i = 0;
	while ((*array)[i])
	{
		if (i == 0 || find_token((*array)[i - 1], 0) != -1)
		{
			if (check_alias((*array)[i], var, replace) == 1)
				done = 1;
			(*array)[i] = replace_alias((*array)[i], var, replace);
		}
		if (f_check_var(var, (*array)[i]) == 1)
		{//TODO replace aussi les var d'environemnt la voila voila.
			puts("ici");
			done = 1;
			(*array)[i] = check_var_alias(var, (*array)[i]);
		}
		i++;
	}
	return (done);
}

char		*remove_env(t_var *start, char *str)
{
	char		**array;
	char		*tmp;
	t_replace	*replace;

	replace = NULL;
	array = split_space(str);
	while (1) // TODO faire en sorte qu'on ne peut pas faire de boucle infinie comme bash on ne peut pas replace 2 fois une var.
		if (remove_env_while(&array, start, replace) == 0)
			break ;
	ft_strdel(&str);
	free_replace(replace);
	tmp = make_string(array);
	return (tmp);
}
