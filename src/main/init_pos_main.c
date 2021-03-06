/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_pos_main.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 15:19:18 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 15:26:22 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/termcaps.h"

void			main_init_pos(t_pos *pos, t_var *my_env)
{
	pos->is_complete = 1;
	pos->last_cmd_on_bg = 0;
	pos->shtheme = 1;
	pos->ret = 1;
	pos->ans = NULL;
	pos->exit_mode = -100;
	pos->ctrl_hist_cmd = NULL;
	pos->prompt = ft_strdup("$ ");
	pos->error_printed = 0;
	to_stock(pos, 0);
	tcgetattr(0, &(pos->old_term));
	tcgetattr(0, &(pos->my_term));
	if ((pos->pwd = ft_strdup(ft_get_val("PWD", my_env, ENVIRONEMENT))) == NULL
			|| verif_path(pos->pwd, 0, 0) == 0)
		pos->pwd = getcwd(NULL, 1000);
}
