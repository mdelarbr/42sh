/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:45:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 11:53:19 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

int		get_term(void)
{
	int		ret;
	char	*name;

	ret = 0;
	name = getenv("TERM");
	if (name == NULL)
	{
		ft_putstr("TERM unset, please set it\n");
		return (0);
	}
	ret = tgetent(NULL, name);
	if (ret == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ret == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_select	*select;
	t_env		*var;

	var = init_env(env);
	if (get_term() == -1)
		return (0);
	if (isatty(2) == 0)
		return (0);
	select = init_term(select);
	while (1)
	{
		if (key_hook() == -1)
			break ;
	}
	tcsetattr(2, TCSANOW, &(OTERM));
	return (0);
}
