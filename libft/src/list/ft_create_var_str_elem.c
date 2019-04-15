/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_var_str_elem.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 05:16:00 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 09:22:50 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

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

t_var		*create_var_str_elem(char *var, char *val)
{
	t_var	*list;

	list = malloc(sizeof(t_var));
	if (list)
	{
		list->var = ft_strdup(var);
		list->val = ft_strdup(val);
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}
