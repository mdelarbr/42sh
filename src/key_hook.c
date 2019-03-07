/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_hook.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 18:24:48 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 14:38:53 by mjalenqu    ###    #+. /#+    ###.fr     */
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
	int		i;

	i = ft_strlen(str);
	dest = malloc(sizeof(char) * (i + 2));
	dest = ft_strcpy(dest, str);
	dest[i] = c;
	dest[i + 1] = '\0';
	ft_strdel(&str);
	return (dest);
}

int		check_key(long c)
{
	char *cm_cap;

//	printf("--[%ld]--", c), fflush(stdout);
	if (c == LEFT)
	{
		cm_cap = tgetstr("cm", NULL);
		tputs(tgoto(cm_cap, 0, 3), 1, ft_put_c);
		tputs(tgetstr("uc", NULL), 1, ft_put_c);
		ft_putstr("go to the left");
	}
	else if (c == RIGHT)
		ft_putstr("right");
	else if (c == UP)
		ft_putstr("up");
	else if (c == DOWN)
		ft_putstr("down");
	else if (c == TAB)
		ft_putstr("tab");
	else if (c == BACK)
		tputs(tgetstr("eo", NULL), 1, ft_put_c);
	else
		return (1);
	return (0);
}

char	*check_char(char *res, long c)
{
	if (check_key(c) == 0)
		return (res);
	ft_putchar(c);
	tputs(tgoto(tgetstr("uc", NULL), 0, 3), 1, ft_put_c);
	res = ft_fjoin_c(res, c);
//	printf("\n|%s|\n", res);
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
		i++;
//		printf("[%ld]", key), fflush(stdout);
		res = check_char(res, key);
		printf("|%d|", i);
		if (key == 10)
			break ;
		key = 0;
	}
	ft_putstr(res);
	if (ft_strcmp(res, "exit\n") == 0)
		return (-1);
	return (0);
}
