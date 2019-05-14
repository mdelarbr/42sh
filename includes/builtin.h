/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 15:48:11 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/14 15:55:25 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <sys/types.h>
# include <sys/stat.h>

# include "launch.h"
# include "ft_list.h"
# include "ft_str.h"
# include "ft_int.h"

/*
** ft_cd.c
*/

int				ft_cd(char **argv, t_ft *ft_global);
int				ft_cd_special(char *name, char *path_pwd, t_ft *ft_global);
int				ft_change_dir(char *path, t_ft *ft_global, char *old);
int				ft_error_cd(char *error, char *name);

// temporary
int				ft_tabclen(char **tab);

/*
** ft_test.c
*/
int				ft_test(char **argv, t_ft *global);
int				verif_int(char *name);
int				comp_num_operator(char *name1, char *type, char *name2);
int				comp_operator(char *name1, char *type, char *name2);
int				test_simple_operator(char *type, char *name,
				struct stat s_type);
int				simple_operator(char *type, char *name);

/*
** list_env.c
*/
void			add_list_env(t_ft *global, char *name, char *env);

/*
** ft_echo.c
*/
int				ft_echo(char *argv[], t_ft *global);

/*
** ft_exit.c
*/
int				ft_exit(char **argv, t_ft *global);

/*
** ft_builtin.c
*/

int				ft_type(char **argv, t_ft *global);

/*
** builtin_list
*/

# define LEN_BUILTIN_LIST 5

typedef struct	s_builtin
{
	const char	*name;
	int			(*ptr_builtin)(char**, t_ft*);
}				t_builtin;

extern const t_builtin	g_builtin_list[LEN_BUILTIN_LIST];

# define ARGUMENTS "cd: Too many arguments."
# define CD_NO_HOME "cd: No HOME directory."
# define CD_NO_OLDPWD "cd: No OLDPWD directory"
# define CD_NO_ENV "cd: No ENV variable directory"
# define CD_NO_FILE "No such file or directory"
# define CD_NO_RIGHTS "permission denied"

# define SETENV_ALPHANUM "setenv: Variable name must contain alphanumeric char."
# define ENV_ARGUMENTS_MANY "Too many arguments."
# define ENV_ARGUMENTS_FEW "Too few arguments.\n"
# define ENV_VARIABLE_LETTER "Variable name must begin with a letter."

# endif
