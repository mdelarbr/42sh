/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 16:02:30 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 16:08:57 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*point;

	point = *alst;
	while (point->next)
		point = point->next;
	new = point->next;
}
