/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_key_all_path.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 17:39:51 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/23 09:35:43 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

static char		*get_env_path(t_var *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
			return (env->data);
		if (env->next == NULL)
			break ;
		env = env->next;
	}
	return (NULL);
}

static t_htab	*open_path_and_fill_htab(char *path, t_htab *htab, char *name)
{
	DIR				*dirp;
	struct dirent	*read;

	if ((dirp = opendir(path)) == NULL)
		return (htab);
	while ((read = readdir(dirp)) != NULL)
	{
		if (read->d_name[0] != '.' &&
			(ft_strstr_case_unsensitive(read->d_name, name) != -1 || wildcard_match(read->d_name, name)))
		{
			htab = add_list_back_htab(htab);
			htab->content = ft_strdup(read->d_name);
			htab->content_no = htab->prev == NULL ? 0 : htab->prev->content_no + 1;
			if (htab->prev == NULL)
				htab->lenght_max = ft_strlen(htab->content);
			else
				htab->lenght_max =
					htab->prev->lenght_max > ft_strlen(htab->content) ?
					ft_strlen(htab->content) : htab->prev->lenght_max;
			htab->content_type = read->d_type;
		}
	}
	closedir(dirp);
	htab = adjust_lenght_max(htab);
	return (htab);
}

static char		*get_name(t_pos *pos, int i, int j)
{
	char			*name;

	name = NULL;
	i = pos->let_nb;
	if (pos->ans[i] == 0 || pos->ans[i] == '$' || pos->ans[i] == '&' || pos->ans[i] == '|' || pos->ans[i] == ';' || pos->ans[i] == 32)
		i -= 1;
	while (i >= 0 && pos->ans[i] != '|' && pos->ans[i] != '&' && pos->ans[i] != 32 && pos->ans[i] != ';')
		i -= 1;
	i += 1;
	j = i;
	while (pos->ans[j] && pos->ans[j] != '|' &&
		pos->ans[j] != '&' && pos->ans[j] != 32)
		j += 1;
	name = malloc(j - i + 1);
	name[j - i] = '\0';
	ft_strncpy(name, pos->ans + i, j - i);
	print_info(pos);
	return (name);
}

t_htab			*looking_for_all(t_pos *pos, t_htab *htab, char **name)
{
	t_var			*env;
	char			**all_path;
	int				i;
	int				j;

	i = 0;
	j = 0;
	*name = get_name(pos, i, j);
	env = stock(NULL, 6);
	if ((all_path = ft_strsplit(get_env_path(env), ':')) == NULL)
		return (NULL);
	while (all_path[i])
	{
		htab = open_path_and_fill_htab(all_path[i], htab, *name);
		i += 1;
	}
	if (htab)
		htab = sort_list_htab(htab);
	ft_tabdel(all_path);
	return (htab);
}