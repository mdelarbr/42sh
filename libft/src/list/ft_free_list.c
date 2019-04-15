/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_list.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 13:10:13 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:14:17 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_free_list(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *list;
	while (tmp)
	{
		free(tmp->content);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
