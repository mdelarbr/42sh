/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_expansions_types.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/23 12:37:35 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 10:17:25 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

t_hist			*number_expansion(char **new_ans, t_hist *hist, char *expansion
				, t_pos *pos)
{
	int			index;
	int			error;

	error = 0;
	index = 0;
	while (hist->prev)
		hist = hist->prev;
	if (ft_strlen(expansion + 2) > 9)
		error = 1;
	else
		index = ft_atoi(expansion + 1);
	if (index > 0 && error == 0)
	{
		while (--index > 0 && hist->next)
			hist = hist->next;
	}
	if (hist->cmd == NULL || index > 0 || hist->next == NULL || error == 1)
	{
		error_handling(pos, expansion, -2);
		*new_ans = ft_secure_free(*new_ans);
	}
	else
		*new_ans = ft_strjoinf(*new_ans, hist->cmd, 1);
	return (hist);
}

t_hist			*negative_number_expansion(char **new_ans, t_hist *hist,
				char *expansion)
{
	int			index;
	int			error;
	t_pos		*pos;

	error = 0;
	index = 0;
	if (ft_strlen(expansion + 2) > 9)
		error = 1;
	else
		index = ft_atoi(expansion + 2);
	while (index > 0 && hist->prev && error == 0)
	{
		hist = hist->prev;
		index--;
	}
	if (index > 0 || hist->cmd == NULL || error == 1)
	{
		pos = stock(NULL, 1);
		error_handling(pos, expansion, -2);
		*new_ans = ft_secure_free(*new_ans);
	}
	else
		*new_ans = ft_strjoinf(*new_ans, hist->cmd, 1);
	return (hist);
}

t_hist			*word_finding_expansion(char **new_ans, t_hist *hist,
				char *expansion)
{
	int			check;
	t_pos		*pos;

	check = 0;
	while (hist->prev)
	{
		hist = hist->prev;
		if (ft_strncmp(hist->cmd, expansion + 1, ft_strlen(expansion) - 1) == 0)
		{
			*new_ans = ft_strjoinf(*new_ans, hist->cmd, 1);
			check += 1;
			break ;
		}
	}
	if (check == 0)
	{
		pos = stock(NULL, 1);
		error_handling(pos, expansion, -2);
		*new_ans = ft_secure_free(*new_ans);
	}
	return (hist);
}

t_hist			*double_exclamation_expansion(char **new_ans, t_hist *hist,
				char *expansion)
{
	t_pos		*pos;

	if (hist && hist->prev)
		*new_ans = ft_strjoinf(*new_ans, hist->prev->cmd, 1);
	else
	{
		pos = stock(NULL, 1);
		error_handling(pos, expansion, -2);
		*new_ans = ft_secure_free(*new_ans);
	}
	return (hist);
}

t_hist			*get_expansion_type(char *expansion, t_hist *hist,
				char **new_ans, int *i)
{
	if (expansion[1] == '!')
		hist = double_exclamation_expansion(new_ans, hist, expansion);
	else if (expansion[1] >= 48 && expansion[1] <= 57)
		hist = number_expansion(new_ans, hist, expansion, stock(NULL, 1));
	else if (expansion[1] == '-' && expansion[2] >= 47 && expansion[2] <= 57)
		hist = negative_number_expansion(new_ans, hist, expansion);
	else if (expansion[1] && expansion[1] != '!' &&
		(expansion[1] < 9 || expansion[1] > 13) && expansion[1] != 32)
		hist = word_finding_expansion(new_ans, hist, expansion);
	else
		*i += 1;
	return (hist);
}
