/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mateodelarbre <mateodelarbre@student.le    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:44:02 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 17:53:06 by mateodelarb ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "lexeur.h"
# include <unistd.h>

typedef	struct			s_process
{
	struct s_process	*next;
	char				**cmd;
	pid_t				pid;
	char				completed;
	char				stopped;
}						t_process;

typedef struct			s_job
{
	struct s_job		*next;
	t_process			*p;
	pid_t				*pgid;
	char				completed;
	char				stopped;
}						t_job;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 exec.c                                     ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		start_exec(t_lexeur **res);

#endif
