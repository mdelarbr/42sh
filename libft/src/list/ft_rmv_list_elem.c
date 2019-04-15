/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rmv_list_elem.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 13:07:08 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:20:44 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

static int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void			ft_rmv_list_elem(char *str, t_list **alist)
{
	t_list *list;
	t_list *tmp;

	list = *alist;
	if (ft_strcmp(str, list->content) == 0)
	{
		(*alist) = (*alist)->next;
		list->next = NULL;
		ft_free_list(&list);
		return ;
	}
	list = list->next;
	tmp = *alist;
	while (list)
	{
		if (ft_strcmp(str, list->content) == 0)
		{
			tmp->next = list->next;
			list->next = NULL;
			ft_free_list(&list);
			break ;
		}
		tmp = tmp->next;
		list = list->next;
	}
}
