/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   forty_two.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 17:29:49 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 09:12:01 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FORTY_TWO_H
# define FT_FORTY_TWO_H

# include "ft_str.h"
# include "ft_unix.h"
# include "ft_int.h"
# include "ft_list.h"

/*
********************************************************************************
**                                                                  Structures *
********************************************************************************
*/

typedef struct s_ft
{
	t_var		*env;
	int			env_nb;
	t_list		*his;
	int			fd_his;
	int			fd_alias;
}				t_ft;

/*
********************************************************************************
**                                                                   Fonctions *
********************************************************************************
*/

void			ft_print_shell(void);
void			ft_print_shell_a(int w);
void			ft_print_shell_b(int w);
void			ft_print_shell_c(int w);
void			ft_print_shell_d(int w);
void			ft_print_shell_e(int w);

t_ft			*ft_getstruct(char **env);

void			ft_error(int nb);

void			ft_free_struct(void);
void			ft_free_env(void);

int				ft_get_env(char **env, t_var **var);
#endif
