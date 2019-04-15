/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_list_elem.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 12:56:59 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 12:59:01 by shthevak    ###    #+. /#+    ###.fr     */
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

t_list		*create_list_elem(char *elem)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->content = ft_strdup(elem);
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}
