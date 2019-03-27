/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_term.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 17:27:12 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 11:14:40 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

t_select	*init_term(t_select *select)
{
	select = malloc(sizeof(t_select));
	if (tcgetattr(0, &(OTERM)) == -1 || tcgetattr(0, &(MTERM)) == -1)
		return (NULL);
	MTERM.c_lflag &= ~(ICANON | ECHO);
	MTERM.c_cc[VMIN] = 1;
	MTERM.c_cc[VTIME] = 0;
	if (tcsetattr(2, TCSANOW, &(MTERM)) == -1)
		return (NULL);
//	tputs(tgetstr("vi", NULL), 1, ft_put_c);
	return (select);
}
