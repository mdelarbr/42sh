/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <shthevak@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 17:27:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:06:29 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"
void		test_pipe(char **argv_1, char **argv_2, char **env_test);

void	ft_print_shell(void)
{
	int w;

	w = ft_terminal_w(STDIN_FILENO) - 48;
	if (w >= 0)
	{
		w = w / 2;
		ft_print_shell_a(w);
		ft_print_shell_b(w);
		ft_print_shell_c(w);
		ft_print_shell_d(w);
		ft_print_shell_e(w);
	}
}

int		main(int av, char **ac, char **env)
{
	t_ft	*ft;

	//ft_print_shell();
	if (!(ft = ft_getstruct(env)))
		ft_error(1);
	char		**argv_1;
	char		**argv_2;

	argv_1 = ft_strsplit("ls -l", ' ');
	argv_2 = ft_strsplit("wc", ' ');
	test_pipe(argv_1, argv_2, env);
	ft_free_struct();
	return (0);
}
