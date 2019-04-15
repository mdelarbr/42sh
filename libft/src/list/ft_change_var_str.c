/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_change_var_str.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 07:10:40 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 09:24:52 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	ft_strlen(const char *str)
{
	const char *s;

	if (str == NULL)
		return (0);
	s = str;
	while (*s != '\0')
		s++;
	return (s - str);
}

static char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void		ft_change_env_str(char *var, char *val, t_var **env)
{
	t_var		*list;
	t_var		*nlist;
	int			i;
	char		**new;

	list = *env;
	i = 0;
	while (list)
	{
		if (ft_strcmp(list->var, var) == 0)
		{
			free(list->val);
			list->val = ft_strdup(val);
			i++;
		}
		list = list->next;
	}
}
