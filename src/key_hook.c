/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 18:24:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 04:07:51 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void	put_index(char *str, int i, t_wind *wind)
{
	int j;

	j = 0;
	while (str[j])
	{
		tputs(tgetstr("dl", NULL), 1, ft_put_c);
		tputs(tgoto(tgetstr("cm", NULL), 0, PLINE + 1), 1, ft_put_c);
		ft_putcolor(BRED, "prompt->", RESET);
		if (j == i)
		{
			tputs(tgoto(tgetstr("cm", NULL), PCOL + 8, PLINE), 1, ft_put_c);
			tputs(tgetstr("mr", NULL), 1, ft_put_c);
			ft_putchar(str[j]);
			tputs(tgetstr("me", NULL), 1, ft_put_c);
		}
		else
			ft_putchar(str[j]);
		j++;
	}
	tputs(tgoto(tgetstr("cm", NULL), PCOL, PLINE), 1, ft_put_c);
	if (i > j)
	{
		tputs(tgetstr("mr", NULL), 1, ft_put_c);
		ft_putchar(' ');
		tputs(tgetstr("me", NULL), 1, ft_put_c);
	}
}

int		ft_put_c(int c)
{
	write(1, &c, 1);
	return (0);
}

char	*ft_fjoin_c(char *str, char c)
{
	char	*dest;
	int		len;

	len = ft_strlen(str);
	dest = malloc(sizeof(char) * (len + 2));
	dest = ft_strcpy(dest, str);
	dest[len] = c;
	dest[len + 1] = '\0';
	ft_strdel(&str);
	return (dest);
}

char	*ft_fjoin(char *str, char c, int i)
{
	char	*dest;
	char	*tmp;
	int		x;

	x = ft_strlen(str);
	dest = ft_strsub(str, 0, i);
	dest = ft_fjoin_c(dest, c);
	tmp = ft_strsub(str, i, x);
	dest = ft_strfjoin(dest, tmp);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (dest);
}

int		check_key(long c, t_wind *wind)
{
	if (c == LEFT)
	{
		if (PCOL > 2)
		{
			tputs(tgetstr("le", NULL), 0, ft_put_c);
			(PCOL) -= 2;
//			tputs(tgoto(tgetstr("cm", NULL), PCOL, PLINE + 1), 0, ft_put_c);
		}
		else
		{
			PCOL = 0;
			tputs(tgetstr("le", NULL), 0, ft_put_c);
		}
	}
	else if (c == RIGHT)
		(PCOL)++;
	else if (c == UP)
		ft_putstr("up");
	else if (c == DOWN)
		ft_putstr("down");
	else if (c == TAB)
		ft_putstr("tab");
	else if (c == BACK)
	{
		tputs(tgetstr("dc", NULL), 1, ft_put_c);
	}
	else
		return (1);
	return (0);
}

char	*check_char(char *res, long c, t_wind *wind)
{
	if (check_key(c, wind) == 0)
		return (res);
	put_index(res, PCOL, wind);
	res = ft_fjoin(res, c, PCOL);
	PCOL++;
	return (res);
}

int		key_hook(t_wind *wind)
{
	long	key;
	char	*res;
	int		i;

	i = 0;
	key = 0;
	res = ft_strdup("");
	ft_putcolor(BRED, "prompt->", RESET);
	tputs(tgetstr("mr", NULL), 1, ft_put_c);
	ft_putchar(' ');
	tputs(tgetstr("me", NULL), 1, ft_put_c);
	while (read(0, &key, 8) > -1)
	{
		if (key == 10)
		{
			tputs(tgetstr("dl", NULL), 1, ft_put_c);
			tputs(tgoto(tgetstr("cm", NULL), 0, PLINE + 1), 1, ft_put_c);
			ft_putcolor2(BRED, "prompt->", RESET, res);
			PLINE += 2;
			PCOL = 1;
			break ;
		}
		res = check_char(res, key, wind);
		if (PCOL < (int)ft_strlen(res))
			put_index(res, PCOL, wind);
		key = 0;
	}
	ft_putchar('\n');
	ft_putendl(res);
	if (ft_strcmp(res, "exit") == 0)
	{
		ft_strdel(&res);
		return (-1);
	}
	ft_strdel(&res);
	return (0);
}
