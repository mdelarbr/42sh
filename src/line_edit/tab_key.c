/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_key.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 10:24:34 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/09 16:07:19 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/termcaps.h"

int        scan_pos_ans(t_pos *pos)
{
	int        i;
	int        word_number;

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

char        *get_full_path(t_pos *pos, char *search)
{
	int        i;
	int        len;

	i = pos->let_nb;
	if (i == 0)
		return (NULL);
	while (i > 0 && pos->ans[i - 1] != ' ')
		i -= 1;
	len = i;
	while (pos->ans[len] && pos->ans[len] != ' ')
		len += 1;
	pos->debug2 = i;
	pos->debug3 = len;
	search = ft_strndup(pos->ans + i, len - i);
	return (search);
}

char		*get_correct_path(char *path)
{
	int		i;
	char	*name;

	name = NULL;
	i = ft_strlen(path) - 1;
	if (i == -1)
		return (NULL);
	while (i >= 0 && path[i] != '/')
		i -= 1;
	if (i < 0)
		return (NULL);
	name = ft_strdup(path + i + 1);
	path[i + 1] = '\0';
	return (name);
}
t_htab        *looking_for_all(t_pos *pos, t_htab *htab)
{
	(void)pos;
	return (htab);
}

t_htab        *looking_for_current(t_pos *pos, t_htab *htab, char *path, char *name)
{
	DIR				*dirp;
	struct dirent	*read;
	char			*pwd;

	(void)pos;
	(void)read;
	(void)name;
	pwd = malloc(1000);
	ft_bzero(pwd, 999);
	if ((dirp = opendir(path)) != NULL)
	{
		free(pwd);
		ft_strcpy(pwd, path);
	}
	else
	{
		pwd = getcwd(pwd, 1000);
		dirp = opendir(pwd);
	}
	
	return (htab);
}

t_htab        *looking_for_var(t_pos *pos, t_htab *htab)
{
	(void)pos;
	return (htab);
}

void        print_htab(t_pos *pos, t_htab *htab)
{
	(void)pos;
	while (htab && htab->prev)
		htab = htab->prev;
	while (htab && htab->next)
	{
		ft_putstr(htab->content);
		htab = htab->next;
	}
}

void        input_is_tab(t_pos *pos)
{
	int        usage;
	t_htab    *htab;
	char    *path;
	char	*name;

	htab = NULL;
	path = NULL;
	name = NULL;
	usage = scan_pos_ans(pos);
	pos->ans_printed = 1;
	pos->debug = usage;
	if (usage == -1)
		return ;
	path = get_full_path(pos, path);
	name = get_correct_path(path);
	ft_printf("\npath = -%s- et name = -%s-\n", path, name);
	exit (0);
	pos->debugchar = path;
	if (usage == 0)
		htab = looking_for_all(pos, htab);
	if (usage == 1)
		htab = looking_for_current(pos, htab, path, name);
	if (usage == 2)
		htab = looking_for_var(pos, htab);
	if (htab)
		print_htab(pos, htab);
	//    free(search);
	return ;
}
