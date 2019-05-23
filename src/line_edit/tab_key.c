/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_key.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 09:39:47 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 09:37:25 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/termcaps.h"

void			debug_htab(t_htab *htab)
{
	if (htab == NULL)
		return ;
	while (htab->prev)
		htab = htab->prev;
	ft_printf("\n\n structure htab");
	while (htab)
	{
		ft_printf("\ncontent = %s // no = %d // type = %d // lenght = %d", htab->content, htab->content_no, htab->content_type, htab->lenght_max);
		htab = htab->next;
	}
}

char			*get_var_name(char *ans, int i)
{
	int		min;

	while (i > 1 && ans[i - 1] != '$')
		i -= 1;
	if (ans[i] == 0 || ans[i] == '$' || ans[i] == '&' || ans[i] == '|' || ans[i] == ';' || ans[i] == 32)
		return (NULL);
	min = i;
	while (ans[i] && ans[i] != '$' && ans[i] != '&' && ans[i] != '|' && ans[i] != ';' && ans[i] != 32)
		i += 1;
	if (ans[i] == 0)
		return (ft_strdup(ans + min));
	return (ft_strndup(ans + min, i - min));
}

t_htab			*looking_for_var(t_pos *pos, t_htab *htab, char **name)
{
	t_var	*var;

	*name = get_var_name(pos->ans, pos->let_nb);
	print_info(pos);
	var = stock(NULL, 6);
	while (var)
	{
		htab = add_list_back_htab(htab);
		htab->content = ft_strdup(var->name);
		htab->content_no = htab->prev == NULL ? 0 : htab->prev->content_no + 1;
		if (htab->prev == NULL)
			htab->lenght_max = ft_strlen(htab->content);
		else
			htab->lenght_max = htab->prev->lenght_max < ft_strlen(htab->content) ? ft_strlen(htab->content) : htab->prev->lenght_max;
		var = var->next;
	}
	if (htab)
	{
		htab = adjust_lenght_max(htab);
		htab = sort_list_htab(htab);
	}
	return (htab);
}

int				is_on_token(char *ans)
{
	if (ft_strncmp(ans, "&&", 2) == 0 || ft_strncmp(ans, "&", 1) == 0 || ft_strncmp(ans, "||", 2) == 0 || ft_strncmp(ans, "|", 1) == 0 || ft_strncmp(ans, ";", 1) == 0 || ft_strncmp(ans, "`", 1) == 0)
		return (1);
	return (0);
}

int				is_on_var(t_pos *pos)
{
	int		i;

	i = pos->let_nb - 1;
	while (i >= 0 && pos->ans[i] != 32 && is_on_token(pos->ans + i) == 0)
	{
		if (pos->ans[i] == '$')
			return (1);
		i -= 1;
	}
	return (0);
}

int				scan_pos_ans(t_pos *pos)
{
	int			i;
	int			word_number;

	i = 0;
	word_number = 0;
	if (pos->let_nb == 0)
		return (-1);
	if (is_on_var(pos) == 1)
		return (2);
	while (pos->ans[i] == ' ')
		i += 1;
	if (i == pos->let_nb)
		return (-1);
	while (pos->ans[i] && i < pos->let_nb)
	{
		if (pos->ans[i] == ' ')
		{
			while (pos->ans[i] == ' ' && i < pos->let_nb)
				i += 1;
			if (pos->ans[i] != ' ')
				word_number += 1;
		}
		else if (is_on_token(pos->ans + i))
		{
			word_number = 0;
			i += 1;
			while (pos->ans[i] == ' ' && i < pos->let_nb)
				i += 1;
			if (i == pos->let_nb)
				return (-1);
		}
		else
			i += 1;
	}
	if (word_number == 0)
		return (0);
	if (word_number > 0)
		return (1);
	return (1);
}

void			input_is_tab(t_pos *pos)
{
	int		usage;
	char	*path;
	char	*name;
	t_htab	*htab;

	htab = NULL;
	pos->ans_printed = 1;
	if ((usage = scan_pos_ans(pos)) == -1)
		return ;
	path = get_full_path(pos);
	name = get_correct_path(path);
	if (usage == 0)
		htab = looking_for_all(pos, htab, &name);
	else if (usage == 1)
		htab = looking_for_current(pos, htab, &path, &name);
	else if (usage == 2)
		htab = looking_for_var(pos, htab, &name);
	if (htab && name == NULL && (usage == 1 || usage == 2))
		prepare_to_print_htab(pos, htab);
	else if (htab)
		htab = prepare_auto_complete(pos, htab, name);
	ft_free_void(path, name, NULL, NULL);
	print_info(pos);
	free_htab(htab);
}
