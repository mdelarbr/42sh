/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list_elem.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 12:59:22 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:14:04 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_add_list_elem(t_list **l, t_list *new)
{
	t_list	*tmp;

	if (*l == NULL)
		*l = new;
	else
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
