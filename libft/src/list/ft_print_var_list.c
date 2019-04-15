/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_var_list.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 05:55:33 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 05:59:29 by shthevak    ###    #+. /#+    ###.fr     */
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

void		ft_print_var_list(t_var **env)
{
	t_var *list;

	list = *env;
	while (list)
	{
		ft_putstr(list->var);
		ft_putstr("=");
		ft_putstr(list->val);
		ft_putstr("\n");
		list = list->next;
	}
}
