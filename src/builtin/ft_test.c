/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 12:55:43 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 14:16:23 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include "../../includes/builtin.h"

// prinf a changer
// erreurs multiples a changer

int			verif_int(char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if ((i == 0 && name[i] == '-') ||
			(name[i] >= '0' && name[i] <= '9'))
			i++;
		else
		{
			printf("test: integer expression expected: %s\n", name);
			return (-1);
		}
	}
	return (0);
}


int			comp_num_operator(char *name1, char *type, char *name2)
{
	if (verif_int(name1) == -1 || verif_int(name2) == -1)
		return (2);
	if (ft_strcmp(type, "-eq") == 0)
		return (ft_atoi(name1) == ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-ne") == 0)
		return (ft_atoi(name1) != ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-ge") == 0)
		return (ft_atoi(name1) >= ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-lt") == 0)
		return (ft_atoi(name1) < ft_atoi(name2)) ? 0 : 1;
	else if (ft_strcmp(type, "-le") == 0)
		return (ft_atoi(name1) <= ft_atoi(name2)) ? 0 : 1;
	else
	{
		printf("test: unknown condition: %s\n", type);
		return (2);
	}
}

int			comp_operator(char *name1, char *type, char *name2)
{
	if (ft_strcmp(type, "=") == 0)
		return (ft_strcmp(name1, name2) == 0) ? 0 : 1;
	else if (ft_strcmp(type, "!=") == 0)
		return (ft_strcmp(name1, name2) != 0) ? 0 : 1;
	else if (type[0] != '-')
	{
		printf("test: condition expected: %s\n", type);
		return (1);
	}
	else
		return (comp_num_operator(name1, type, name2));
	return (2);
}

int			test_simple_operator(char *type, struct stat s_type)
{
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
	return (0);
}

int			simple_operator(char *type, char *name)
{
	struct stat s_type;

	if (type[0] != '-')
	{
		printf("test: unknown condition: %s\n", type);
		return (2);
	}
	if (ft_strlen(type) < 2)
	{
		printf("zsh: parse error: condition expected: %s\n", type);
		return (2);
	}
	if (!ft_strchr("ebcdfLpSgurwx", type[1]) || ft_strlen(type) > 2)
	{
		printf("test: unknown condition: %s\n", type);
		return (2);
	}
	if (stat(name, &s_type) == -1)
		return (1);
	if (ft_strcmp(type, "-e") == 0)
		return (0);
	if (ft_strcmp(type, "-b") == 0)
		return ((s_type.st_mode & S_IFMT) == S_IFBLK) ? 0 : 1;
	return (test_simple_operator(type, s_type));
}

int			ft_test(t_process *p, t_var **var)
{
	int i;
	int inv;

	var = NULL;
	i = 0;
	if (ft_tabclen(p->cmd) <= 1)
		return (1);
	if (ft_strcmp(p->cmd[1], "!") == 0)
	{
		inv = 1;
		p->cmd++;
	}
	if (ft_tabclen(p->cmd) == 2 && p->cmd[1] == NULL)
		i = 1;
	else if (ft_tabclen(p->cmd) == 3)
		i = simple_operator(p->cmd[1], p->cmd[2]);
	else if (ft_tabclen(p->cmd) == 4)
		i = comp_operator(p->cmd[1], p->cmd[2], p->cmd[3]);
	else
	{
		printf("test: too many arguments");
		return (2);
	}
	if (inv == 1)
		i = (i == 0) ? 1 : 0;
	printf("%d\n", i);
	return (i);
}
