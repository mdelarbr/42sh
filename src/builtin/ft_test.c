/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 12:55:43 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 14:46:50 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtin.h"

int			comp_operator(char *name1, char *type, char *name2)
{
	if (ft_strcmp(type, "=") == 0)
		return (ft_strcmp(name1, name2) == 0) ? 0 : 1;
	if (ft_strcmp(type, "!=") == 0)
		return (ft_strcmp(name1, name2) != 0) ? 0 : 1;
	if (ft_strcmp(type, "-eq") == 0)
		return (ft_atoi(name1) == ft_atoi(name2)) ? 0 : 1;
	if (ft_strcmp(type, "-ne") == 0)
		return (ft_atoi(name1) != ft_atoi(name2)) ? 0 : 1;
	if (ft_strcmp(type, "-ge") == 0)
		return (ft_atoi(name1) >= ft_atoi(name2)) ? 0 : 1;
	if (ft_strcmp(type, "-lt") == 0)
		return (ft_atoi(name1) < ft_atoi(name2)) ? 0 : 1;
	if (ft_strcmp(type, "-le") == 0)
		return (ft_atoi(name1) <= ft_atoi(name2)) ? 0 : 1;
	return (-1);
}

int			simple_operator(char *type, char *name)
{
	struct stat s_type;

	if (stat(name, &s_type) == -1)
		return (1);
	if (ft_strcmp(type, "-b") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFBLK) ? 0 : 1;
	if (ft_strcmp(type, "-c") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFCHR) ? 0 : 1;
	if (ft_strcmp(type, "-d") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFDIR) ? 0 : 1;
	if (ft_strcmp(type, "-f") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFREG) ? 0 : 1;
	if (ft_strcmp(type, "-L") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFLNK) ? 0 : 1;
	if (ft_strcmp(type, "-p") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFIFO) ? 0 : 1;
	if (ft_strcmp(type, "-S") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFSOCK) ? 0 : 1;
	if (ft_strcmp(type, "-g") == 0)
		return (s_type.st_mode & S_ISGID) ? 0 : 1;
	if (ft_strcmp(type, "-u") == 0)
		return (s_type.st_mode & S_ISUID) ? 0 : 1;
	if (ft_strcmp(type, "-r") == 0)
		return (s_type.st_mode & S_IRUSR) ? 0 : 1;
	if (ft_strcmp(type, "-w") == 0)
		return (s_type.st_mode & S_IWUSR) ? 0 : 1;
	if (ft_strcmp(type, "-x") == 0)
		return (s_type.st_mode & S_IXUSR) ? 0 : 1;
	return (-1);
}

int			ft_test(char **argv)
{
	int i;


	i = 0;
	if (ft_tabclen(argv) == 1)
		return (1);
	else if (ft_tabclen(argv) == 2)
	{
		if (argv[1] == NULL)
			i = 1;
	}
	else if (ft_tabclen(argv) == 3)
	{
		i = simple_operator(argv[1], argv[2]);
	}
	else
		i = comp_operator(argv[1], argv[2], argv[3]);
	printf("->%d\n", i);
	return (i);
}
