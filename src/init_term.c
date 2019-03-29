/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_term.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 17:27:12 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 15:59:01 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

t_select	*init_term(t_all *all)
{
	all->select = malloc(sizeof(t_select));
	if (tcgetattr(0, &(OTERM)) == -1 || tcgetattr(0, &(MTERM)) == -1)
		return (NULL);
	MTERM.c_lflag &= ~(ICANON | ECHO);
	MTERM.c_cc[VMIN] = 1;
	MTERM.c_cc[VTIME] = 0;
	if (tcsetattr(2, TCSANOW, &(MTERM)) == -1)
		return (NULL);
	return (all->select);
}

int			get_term(void)
{
	int		ret;
	char	*name;

	ret = 0;
	name = getenv("TERM");
	if (name == NULL)
	{
		ft_putstr("TERM unset, please set it\n");
		return (0);
	}
	ret = tgetent(NULL, name);
	if (ret == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ret == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int			check_term(void)
{
	if (get_term() == -1)
		return (-1);
	if (isatty(2) == 0)
		return (-1);
	return (0);
}
