/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 18:24:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 11:54:12 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

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
	return (dest);
}

char	*ft_fjoin(char *str, char c, int i)
{
	char	*dest;
	char	*tmp;
	int		x;

	x = ft_strlen(str);
	printf("|||i = %d|x = %d|||", i, x);
	dest = ft_strsub(str, 0, i);
	dest = ft_fjoin_c(dest, c);
	tmp = ft_strsub(str, i, x);
	dest = ft_strfjoin(dest, tmp);
	ft_strdel(&str);
	return (dest);
}

int		check_key(long c, int *i)
{
	char *cm_cap;

	if (c == LEFT)
	{
		cm_cap = tgetstr("cm", NULL);
		tputs(tgoto(cm_cap, 0, 3), 0, ft_put_c);
		tputs(tgetstr("uc", NULL), 0, ft_put_c);
		if (*i > 0)
			(*i) -= 2;
	}
	else if (c == RIGHT)
		(*i)++;
	else if (c == UP)
		ft_putstr("up");
	else if (c == DOWN)
		ft_putstr("down");
	else if (c == TAB)
		ft_putstr("tab");
	else if (c == BACK)
	{
		tputs(tgoto(tgetstr("le", NULL), 0, 3), 2, ft_put_c);
		tputs(tgetstr("dc", NULL), 1, ft_put_c);
	}
	else
		return (1);
	return (0);
}

char	*check_char(char *res, long c, int *i)
{
	if (check_key(c, i) == 0)
		return (res);
	(*i)++;
	ft_putchar(c);
	tputs(tgoto(tgetstr("uc", NULL), 0, 3), 2, ft_put_c);
	res = ft_fjoin(res, c, *i);
	return (res);
}

int		key_hook(void)
{
	long	key;
	char	*res;
	int		i;

	i = 0;
	key = 0;
	res = ft_strdup("");
	ft_putcolor(BRED, "prompt->", RESET);
	while (read(0, &key, 8) > -1)
	{
		if (key == 10)
			break ;
		res = check_char(res, key, &i);
//		i++;
		if (i < ft_strlen(res))
		{
			tputs(tgetstr("dl", NULL), 0, ft_put_c);
			ft_putstr(res);
		}
		key = 0;
		printf("%d", i);
	}
	ft_putchar('\n');
	ft_putendl(res);
	if (ft_strcmp(res, "exit") == 0)
		return (-1);
	return (0);
}
