/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 15:48:11 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 18:39:31 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "execute.h"

/*
** ft_cd.c
*/

int				ft_cd(char **argv, t_ft *ft_global);
int				ft_cd_special(char *name, char *path_pwd, t_ft *ft_global);
int				ft_change_dir(char *path, t_ft *ft_global, char *old);
int				ft_error_cd(char *error, char *name);

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
