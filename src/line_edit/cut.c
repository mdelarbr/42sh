/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cut.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 09:34:46 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 13:39:31 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"


char	*ft_strndup(char *s1, int start, int end)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	while (s1[start] && start <= end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*remove_cut(char *str, int start, int end)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ft_strlen(str));
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i])
	{
		while (i >= start && i <= end)
			i++;
		res[j] = str[i];
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
        save = ft_strndup(pos->ans, pos->start_select, pos->let_nb);
    else
        save = ft_strndup(pos->ans, pos->let_nb, pos->start_select);
    stock(save, 3);
}

void    cut_char(t_pos *pos)
{
    if (pos->start_select == -1)
        return ;
    save_char(pos);
	if (pos->start_select < pos->let_nb)
		pos->ans = remove_cut(pos->ans, pos->start_select, pos->let_nb);
	else
		pos->ans = remove_cut(pos->ans, pos->let_nb, pos->start_select);
}

// void    paste(t_pos *pos)
// {

// }
