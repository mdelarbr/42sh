/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_var_elem.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 05:25:34 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 07:22:04 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_add_var_elem(t_var **l, t_var *new)
{
	t_var	*tmp;

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
