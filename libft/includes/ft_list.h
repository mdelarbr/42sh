/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 02:55:53 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:15:08 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <unistd.h>

/*
********************************************************************************
**                                                                  Structures *
********************************************************************************
*/

/*
** list
*/

typedef	struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

/*
** var
*/

typedef struct			s_var
{
	void				*var;
	void				*val;
	int					type;
	struct s_var		*next;
}						t_var;

/*
********************************************************************************
**                                                                   Fonctions *
********************************************************************************
*/

t_var					*create_var_str_elem(char *var, char *val);
void					ft_add_var_elem(t_var **l, t_var *ne);
void					ft_print_var_list(t_var **list);
void					ft_change_var_str(char *var, char *val, t_var **env);
void					ft_free_var_list(t_var **list);
void					ft_rmv_var_elem(char *str, t_var **env);

t_list					*create_list_elem(char *elem);
void					ft_add_list_elem(t_list **l, t_list *ne);
void					ft_print_list(t_list **list);
void					ft_rmv_list_elem(char *str, t_list **list);
void					ft_free_list(t_list **list);
#endif
