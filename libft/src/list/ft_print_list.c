/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 13:01:19 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:15:14 by shthevak    ###    #+. /#+    ###.fr     */
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

static void	ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void		ft_print_list(t_list **list)
{
	t_list *elem;

	elem = *list;
	while (elem)
	{
		ft_putstr(elem->content);
		ft_putstr("\n");
		elem = elem->next;
	}
}
