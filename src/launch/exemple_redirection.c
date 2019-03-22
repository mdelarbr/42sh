/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exemple_redirection.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 10:57:59 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 16:51:48 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"
#include <stdio.h>

void		test_redirection(char **comm_1, char **comm_2, char **env, int fd1, int fd2)
{
	int  pfd[2];
	int  pid;

	pipe(pfd);
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], fd2);
		close(pfd[0]);
		execve("/usr/bin/wc", comm_2 , env);
		return ;
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], fd1);
		close(pfd[1]);
		execve("/bin/ls", comm_1, env);
		return ;
	}
}

// remplacer parametre dans read pour ecrire apres O_APPEND a ajouter apres dans le fichier

void		test_file(char **argv_1, char *file, char **env_test)
{
	int	file_fd;

	file_fd = open(file, O_WRONLY|O_CREAT|O_APPEND);
	printf("%d\n", file_fd);
	close(1);
	dup(file_fd);
	execve("/bin/ls", argv_1, env_test);
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
