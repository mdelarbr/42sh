/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 17:27:41 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 13:51:42 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "forty_two.h"

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
//	ft_print_var_list(&(ft->env));
//	ft_print_list(&(ft->his));
	//ft_error(0);
	ft_free_struct();
	return (0);
}
