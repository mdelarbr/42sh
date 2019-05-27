/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_expansion.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 07:05:34 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 13:41:45 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

int				get_expansion_length(char *ans, int i)
{
	int			j;
	int			check;
	int			not_double;

	not_double = 0;
	check = 0;
	j = i;
	while (ans[j] && (ans[j] < 9 || ans[j] > 13) && ans[j] != 32 && check < 2)
	{
		if (ans[j] != '!')
			not_double += 1;
		if (ans[j] == '!' && not_double > 0)
			break ;
		else if (ans[j] == '!')
			check += 1;
		j++;
	}
	return (j);
}

char			*get_expansion_content(char *ans, int i)
{
	char		*new_ans;
	int			j;
	int			k;

	k = 0;
	j = get_expansion_length(ans, i);
	new_ans = ft_strnew(j - i);
	while (i < j)
		new_ans[k++] = ans[i++];
	new_ans[k] = '\0';
	return (new_ans);
}

t_hist			*replace_expansion_by_value(t_pos *pos, char **ans,
				t_hist *hist, int *i)
{
	char		*new_ans;
	int			end_exp;
	int			j;
	char		*expansion;

	expansion = get_expansion_content(*ans, *i);
	j = 0;
	end_exp = get_expansion_length(*ans, *i);
	new_ans = ft_strnew(*i);
	while (j < *i)
	{
		new_ans[j] = ans[0][j];
		j++;
	}
	new_ans[j] = '\0';
	j = *i;
	hist = get_expansion_type(expansion, hist, &new_ans, i);
	if (j != *i)
		return (no_expansion_found(&expansion, &new_ans, hist));
	if (new_ans != NULL && ans != NULL)
		new_ans = filling_ans_with_new_ans(pos, new_ans, ans, end_exp);
	else
		new_ans = new_ans_not_valid(ans, new_ans, i);
	expansion = ft_secure_free(expansion);
	return (hist);
}

t_hist			*exit_history_expansion(t_hist *hist, char *ans, t_pos *pos)
{
	int			len;

	while (hist->next)
		hist = hist->next;
	if (ans != NULL)
	{
		pos->ans = ft_strnew(ft_strlen(ans));
		pos->ans = ft_strcpy(pos->ans, ans);
	}
	if (ans != NULL && pos->replace_hist > 0)
	{
		clean_at_start(pos);
		print_ans(pos, 0, pos->len_prompt);
		pos->let_nb = ft_strlen(pos->ans);
		pos->history_mode = 0;
	}
	if (ans != NULL)
		ans = ft_secure_free(ans);
	else
		pos->ans = ft_strnew(0);
	len = get_len_with_lines(pos) / pos->max_co;
	if (pos->start_li + len > pos->max_li)
		pos->start_li -= (pos->start_li + len - pos->max_li);
	return (hist);
}

t_hist			*check_history_expansion(t_pos *pos, char *ans, t_hist *hist)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (ft_strchr(ans, '!') == NULL)
		return (hist);
	while (ans && ans[i])
	{
		if (ans[i] == '!')
		{
			j = i;
			hist = replace_expansion_by_value(pos, &ans, hist, &i);
			if (ans != NULL && ans[j] && ans[j + 1] && ans[j + 1] == '!')
				i = j + 2;
		}
		else
			i += 1;
	}
	hist = exit_history_expansion(hist, ans, pos);
	if (pos->error == 1)
		pos->replace_hist = 0;
	return (hist);
}
