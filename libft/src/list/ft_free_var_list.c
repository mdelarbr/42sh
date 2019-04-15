/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_var_list.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 08:45:17 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 09:12:07 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_free_var_list(t_var **list)
{
	t_var *tmp;
	t_var *tmp2;

	tmp = *list;
	while (tmp)
	{
		free(tmp->var);
		free(tmp->val);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
