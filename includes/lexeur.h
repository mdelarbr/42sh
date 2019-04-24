/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexeur.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 13:50:20 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 14:12:30 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEXEUR_H
# define LEXEUR_H

# include "../libft/includes/ft_int.h"
# include "../libft/includes/ft_list.h"
# include "../libft/includes/ft_unix.h"
# include "../libft/includes/ft_str.h"
# include "shell.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define ENVIRONEMENT 0
# define LOCAL 1

typedef enum
{
	T_AND,
	T_EXEC_SIM,
	T_OR,
	T_PIPE,
	T_OUT_D,
	T_OUT_S,
	T_IN_D,
	T_IN_S,
	T_SEMI,
	T_SUB,
	T_ARITHMETIC,
	T_HISTORY
}	e_token;

typedef struct
{
  const char    *name;
  int           size;
  e_token       token;
} t_token;

typedef struct
{
	char        *word;
	e_token     token;
	char        *redirection;
	int			fd;
} t_lexeur;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 lexeur.c                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_lexeur	**start_lex(t_all *all);
int			find_token(char *buf, int i);
int			cnt_wrd(char *buf);
t_token     g_fill_token[10];

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 fill_lexeur.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_lexeur	**fill_lex(char *buf, t_lexeur **tabe);
void		jump_space(char *buf, int *i);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 back_slash.c                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void		fill_lex_solve_back_slash(char *buf, int *i, int *start);
void		cnt_solve_back_slash(char *buf, int *i, int *cnt);
void		del_back_slash(t_lexeur ***tabe);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 redirection.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		*fill_redirection(char *buf, int *i, int token);
t_lexeur	**find_input_redirection(t_lexeur ***tabe);
t_lexeur	**check_redirection(t_lexeur ***tabe);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 redirection.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_lexeur	*find_fd(char *buf, int *i);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 redirection.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		*remove_env(t_all *all, char *str);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 env_replace.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		*find_env_var(t_env *env, char *str, int i);
char		*switch_word(char *str, char *tmp, int i);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 env_replace.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void        check_var(t_env *env, char **str);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 var_replace.c                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

char		*check_var_alias(t_env *env, char *str);
int			f_check_var_alias(t_env *env, char *str);

#endif