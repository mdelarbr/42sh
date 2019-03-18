/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mateodelarbre <mateodelarbre@student.le    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 15:45:25 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 15:06:43 by mateodelarb ###    #+. /#+    ###.fr     */
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

void	free_env(t_env *var)
{
	t_env *tmp;

	tmp = var;
	while (var)
	{
		ft_strdel(&var->name);
		ft_strdel(&var->data);
		var = var->next;
		free(tmp);
		tmp = var;
	}
}

int		main(int ac, char **av, char **env)
{
	t_select	*select;
	t_env		*var;
	t_wind		*wind;

	(void)ac;
	(void)av;
	select = NULL;
	var = init_env(env);
	if (get_term() == -1)
		return (0);
	if (isatty(2) == 0)
		return (0);
	select = init_term(select);
	wind = init_wind();
/*	while (1)
	{
		if (key_hook(wind) == -1)
			break ;
	}
*/
	key_hook(wind);
	tcsetattr(2, TCSANOW, &(OTERM));
	tputs(tgetstr("ve", NULL), 1, ft_put_c);
	free(select);
	free_env(var);
	return (0);
}
