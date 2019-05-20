/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/16 11:50:38 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 16:22:40 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "exec.h"

# define LEN_BUILTIN_LIST 9

typedef struct	s_builtin
{
	const char	*name;
	int			(*ptr_builtin)(t_process*, t_var**);
}				t_builtin;

extern const t_builtin	g_builtin_list[LEN_BUILTIN_LIST];

# include <sys/types.h>
# include <sys/stat.h>

int				ft_test(t_process *p, t_var **var);
int				ft_echo(t_process *p, t_var **var);
int				ft_cd(t_process *p, t_var **var);
int				ft_set(t_process *p, t_var **ptr_var);
int				ft_type(t_process *p, t_var **var);
int				ft_export(t_process *p, t_var **ptr_var);
int				ft_unset(t_process *p, t_var **ptr_var);

char			*ft_get_val(char *name, t_var *var, int type);
int				ft_tabclen(char **array);
void			add_list_env(t_var **var, int type, char *name, char *data);
int				remove_list_var(t_var **ptr_var, int type, char *name);

# define ARGUMENTS "cd: Too many arguments."
# define CD_NO_HOME "cd: No HOME directory."
# define CD_NO_OLDPWD "cd: No OLDPWD directory"
# define CD_NO_ENV "cd: No ENV variable directory"
# define CD_NO_FILE "No such file or directory"
# define CD_NO_RIGHTS "permission denied"

#endif
