/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 08:14:23 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 08:30:13 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int		check_term(void)
{
	int			ret;
	char		*term_type;

	term_type = getenv("TERM");
	ret = 0;
	if (term_type == NULL)
	{
		ft_putstr("TERM must be set (see 'env').\n");
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putstr("Could not access to the termcap database..\n");
		return (-1);
	}
	else if (ret == 0)
	{
		ft_putcolor("Terminal type", term_type, "is not defined in termcap database ");
		ft_putstr("or have too few informations).\n");
		return (-1);
	}
	return (0);
}
