/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <shthevak@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 14:35:20 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 11:21:27 by husahuc     ###    #+. /#+    ###.fr     */
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
#endif
