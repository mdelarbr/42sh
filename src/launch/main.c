/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 17:27:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 16:32:26 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "launch.h"

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

	ft_print_shell();
	if (!(ft = ft_getstruct(env)))
		ft_error(1);
/*	ft_putstr("/tmp/a.out\n");
	ft_execute_line("/tmp/a.out", ft);
	ft_putstr("/tmp/test.sh\n");
	ft_execute_line("/tmp/test.sh", ft);
	ft_putstr("/tmp/try2 : no rights\n");
	ft_execute_line("/tmp/try2", ft);
*/	ft_free_struct();
	return (0);
}