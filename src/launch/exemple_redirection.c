/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exemple_redirection.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 10:57:59 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:06:36 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"
#include <stdio.h>

void		test_redirection(char **name1, char **argv_2 char **env, int fd1, int fd2)
{
	int  pfd[2];
	int  pid;

	pipe(pfd);
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		execve("/usr/bin/wc", argv_2 , env_test);
		return ;
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execve("/bin/ls", argv_1, env_test);
		return ;
	}
}

void		test_pipe(char **argv_1, char **argv_2, char **env_test)
{
	int  pfd[2];
	int  pid;

	pipe(pfd);
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		execve("/usr/bin/wc", argv_2 , env_test);
		return ;
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execve("/bin/ls", argv_1, env_test);
		return ;
	}
}
