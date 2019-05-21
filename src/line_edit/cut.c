/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cut.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 09:34:46 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:14:28 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void	clear_and_print(t_pos *pos)
{
	tputs(tgoto(tgetstr("cm", NULL), pos->start_co, pos->start_li),
							1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	print_ans(pos, 0, pos->start_co);
	pos->ans_printed = 1;
	tputs(tgoto(tgetstr("cm", NULL), pos->act_co, pos->act_li),
							1, ft_putchar);
}

char	*remove_cut(char *str, int start, int end)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || str[0] == '\0' || (start == 0 && end == ft_strlen(str)))
	{
		ft_strdel(&str);
		res = ft_strdup("");
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i] && i >= start && i <= end)
			i++;
		res[j] = str[i];
		if (str[i])
			i++;
		j++;
	}
	res[j] = '\0';
	ft_strdel(&str);
	return (res);
}

void    save_char(t_pos *pos)
{
    char    *save;

    save = NULL;
    if (pos->start_select < pos->let_nb)
        save = ft_strndup(pos->ans + pos->start_select, pos->let_nb - pos->start_select + 1);
    else
        save = ft_strndup(pos->ans + pos->let_nb, pos->start_select - pos->let_nb + 1);
    stock(save, 3);
}

void    cut_char(t_pos *pos)
{
	int len;

    if (pos->start_select == -1)
        return ;
    save_char(pos);
	if (pos->start_select < pos->let_nb)
	{
		pos->ans = remove_cut(pos->ans, pos->start_select, pos->let_nb);
		len = pos->let_nb - pos->start_select;
		pos->let_nb = pos->start_select;
		pos->act_co -= len;
	}
	else
		pos->ans = remove_cut(pos->ans, pos->let_nb, pos->start_select);
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
	clear_and_print(pos);
}

void	paste(t_pos *pos)
{
	char	*tmp;
	char	co[2];
	int		i;

	tmp = stock(NULL, 4);
	if (tmp == NULL)
		return ;
	i = 0;
	co[1] = '\0';
	while (tmp[i])
	{
		co[0] = tmp[i];
		input_is_printable_char(pos, co);
		i++;
	}
	clear_and_print(pos);
}

void	copy(t_pos *pos)
{
	if (pos->start_select == -1)
        return ;
    save_char(pos);
	pos->start_select = -1;
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
	clear_and_print(pos);
}

void	check_copy(unsigned char *buf, t_pos *pos)
{
	if (buf[0] == 226 && buf[1] == 137 && buf[2] == 136)
		cut_char(pos);
	else if (buf[0] == 195 && buf[1] == 167)
		copy(pos);
	else if (buf[0] == 226 && buf[1] == 136 && buf[2] == 154)
		paste(pos);
	pos->start_select = -1;
}
