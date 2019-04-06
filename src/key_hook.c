/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 18:24:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 10:08:39 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	print_test(char *str, t_all *all)
{
	int i;
	int b;

	i = 0;
	b = 0;
	if (str == NULL)
		return ;
	tputs(tgetstr("dl", NULL), 1, ft_put_c);
	tputs(tgoto(tgetstr("cm", NULL), 0, PLINE), 1, ft_put_c);
	ft_putcolor(BRED, "prompt->", RESET);
	while (str[i])
	{
		if (i == PCOL)
		{
			tputs(tgetstr("vi", NULL), 1, ft_put_c);
			tputs(tgoto(tgetstr("cm", NULL), i + 8, PLINE), 1, ft_put_c);
			tputs(tgetstr("mr", NULL), 1, ft_put_c);
			ft_putchar(str[i]);
			tputs(tgetstr("me", NULL), 1, ft_put_c);
			b = 1;
		}
		else if (i == COL)
		{
			PLINE++;
			PCOL = 0;
		}
		else
		{
			tputs(tgoto(tgetstr("cm", NULL), i + 8, PLINE), 1, ft_put_c);
			ft_putchar(str[i]);
		}
		i++;
	}
	if (b == 0)
		tputs(tgetstr("ve", NULL), 1, ft_put_c);
}

int		ft_put_c(int c)
{
	write(1, &c, 1);
	return (0);
}

char	*remove_char(char **str, int i)
{
	char	*res;
	char	*tmp;

	if (i < 1 || !(*str))
		return (*str);
	if (i == 1)
		res = ft_strsub(*str, 1, ft_strlen(*str) - 1);
	else
	{
		res = ft_strsub(*str, 0, i - 1);
		tmp = ft_strsub(*str, i, ft_strlen(*str));
		res = ft_strfjoin(res, tmp);
	}
	ft_strdel(str);
	return (res);
}

int		check_key(long c, t_all *all, char **res)
{
	if (c == LEFT)
	{
		if (PCOL > 1)
			(PCOL) -= 1;
		else
		{
			PCOL = 0;
			tputs(tgetstr("le", NULL), 0, ft_put_c);
		}
	}
	else if (c == RIGHT)
	{
		if (PCOL < ft_strlen(*res))
			PCOL++;
	}
	else if (c == UP)
		do_up(all);
	else if (c == DOWN)
		do_down(all);
	else if (c == TAB)
		ft_putstr("tab");
	else if (c == BACK)
		do_back(all, res);
	else
		return (1);
	return (0);
}

char	*check_char(char *res, long c, t_all *all)
{
	int		i;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	i = check_key(c, all, &res);
	if (i == 0)
		return (res);
	(void)CMD;
	ft_strjoin_insert(&res, tmp, PCOL);
	if (PCOL == COL)
	{
		PLINE++;
		PCOL = 0;
	}
	else
		PCOL++;
	return (res);
}

int		*key_hook(t_all *all)
{
	long		key;

	key = 0;
	ft_putcolor(BRED, all->prompt, RESET);
	PCOL = 0;
	while (all->last->next != NULL)
		all->last = all->last->next;
	all->last->next = add_history(all);
	all->last = all->last->next;
	while (read(0, &key, 8) > -1)
	{
		if (key == 10)
		{
			tputs(tgetstr("dl", NULL), 1, ft_put_c);
			tputs(tgoto(tgetstr("cm", NULL), 0, PLINE), 1, ft_put_c);
			ft_putcolor2(BRED, "prompt->", RESET, all->last->cmd);
			PLINE += 2;
			PCOL = 1;
			return (0);
		}
		all->last->cmd = check_char(all->last->cmd, key, all);
		print_test(all->last->cmd, all);
		key = 0;
	}
	return (0);
}
