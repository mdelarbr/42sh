/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:40:29 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 19:33:22 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char splitter)
{
	int		i;
	int		word;
	int		word_check;

	i = 0;
	word = 0;
	word_check = 0;
	while (str[i] != '\0')
	{
		while (!(str[i] == splitter || str[i] == '\0'))
		{
			word_check = 1;
			i++;
		}
		if (word_check)
		{
			word += 1;
			word_check = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	return (word);
}

static void	ft_filling(char **split, char *s, char c, int words)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		len = i;
		while (s[len] != c && s[len])
			len++;
		split[j] = ft_strsub(s, i, len - i);
		j++;
		if (len)
			i = len;
	}
	split[words] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		words;

	if (!(s))
		return (0);
	words = ft_countwords(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	ft_filling(split, (char*)s, c, words);
	return (split);
}
