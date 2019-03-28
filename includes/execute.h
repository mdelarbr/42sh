/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <shthevak@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 14:35:20 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 11:30:51 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "ft_list.h"
# include "ft_str.h"

# include "launch.h"
# include "builtin.h"

void	ft_execute_line(char *str, t_ft *ft);
int		ft_is_exec_verbose(char *str);

int		ft_execute(char *exec, char **opt, t_ft *global);

char	**get_env_tab(t_var **var);

void	execute(char **command, t_ft *global);

# define FORK_FAILED "fork has failed"
# define COMMAND_NOT_FOUND "Minishell: command not found: "
# define RIGHTS "permission denied"

#endif
