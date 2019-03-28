/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 18:24:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 10:05:43 by mjalenqu    ###    #+. /#+    ###.fr     */
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

char	*remove_char(char *str, int i)
{
	char	*res;
	int		j;
	int		l;

	j = 0;
	l = 0;
	res = malloc(sizeof(char) * ft_strlen(str));
	if (i == 0)
	{
		while (str[j + 1])
		{
			if (j == i - 1)
				j++;
			res[l] = str[j + 1];
			j++;
			l++;
		}
	}
	else
	{
		while (str[j + 1])
		{
			if (j == i - 1)
				j++;
			res[l] = str[j];
			j++;
			l++;
		}
	}
	res[l] = '\0';
	if (str)
		ft_strdel(&str);
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
		do_up(all, res);
	else if (c == DOWN)
		return (0);
	else if (c == TAB)
		ft_putstr("tab");
	else if (c == BACK)
	{
		if (ft_strlen(*res) > 0)
		{
			(*res) = remove_char(*res, PCOL);
			PCOL--;
			return (0);
		}
	}
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

char	*key_hook(t_all *all)
{
	long		key;
	char		*res;
	int			i;

	i = 0;
	key = 0;
	res = ft_strdup("");
	ft_putcolor(BRED, "prompt->", RESET);
	PCOL = 0;
	while (read(0, &key, 8) > -1)
	{
		if (key == DOWN)
		{
			if (all->history && all->history->next)
			{
				all->history = all->history->next;
				res = all->history->cmd;
			}
		}
		else if (key == 10)
		{
			tputs(tgetstr("dl", NULL), 1, ft_put_c);
			tputs(tgoto(tgetstr("cm", NULL), 0, PLINE), 1, ft_put_c);
			ft_putcolor2(BRED, "prompt->", RESET, res);
			PLINE += 2;
			PCOL = 1;
			return (res);
		}
		res = check_char(res, key, all);
		print_test(res, all);
		key = 0;
	}
	return (0);
}
