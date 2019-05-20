/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_key.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 09:39:47 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/16 17:52:46 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/termcaps.h"

t_htab			*looking_for_var(t_pos *pos, t_htab *htab)
{
	(void)pos;
	return (htab);
}

int				scan_pos_ans(t_pos *pos)
{
	int			i;
	int			word_number;

	i = 0;
	word_number = 0;
	if (pos->let_nb == 0)
		return (-1);
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
		else if (ft_strncmp(pos->ans + i, "&&", 2) == 0 || ft_strncmp(pos->ans + i, "&", 1) == 0 || ft_strncmp(pos->ans + i, "||", 2) == 0)
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
		htab = looking_for_var(pos, htab);
	if (htab && name == NULL && usage == 1)
		prepare_to_print_htab(pos, htab);
	else if (htab)
		htab = prepare_auto_complete(pos, htab, name);
	ft_free_void(path, name, NULL, NULL);
//	print_info(pos);
	free_htab(htab);
}
