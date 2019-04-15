/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rmv_var_elem.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 07:26:29 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:06:35 by shthevak    ###    #+. /#+    ###.fr     */
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

void			ft_rmv_var_elem(char *str, t_var **envir)
{
	t_var *list;
	t_var *tmp;

	list = *envir;
	if (ft_strcmp(str, list->var) == 0)
	{
		(*envir) = (*envir)->next;
		list->next = NULL;
		ft_free_var_list(&list);
		return ;
	}
	list = list->next;
	tmp = *envir;
	while (list)
	{
		if (ft_strcmp(str, list->var) == 0)
		{
			tmp->next = list->next;
			list->next = NULL;
			ft_free_var_list(&list);
			break ;
		}
		tmp = tmp->next;
		list = list->next;
	}
}
