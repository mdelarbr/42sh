/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 09:27:30 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 13:34:42 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "termcaps.h"

void	clear_info(int max_line)
{
	int 	i;

	i = 0;
	while (i < max_line)
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, i), 1, ft_putchar);
		tputs(tgetstr("ce", NULL), 1, ft_putchar);
		i++;
	}
	i = -1;
	while (++i < tgetnum("co"))
		write(1, "-", 1);
}
//			tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
//			printf("pos->ans  = %-140.140s/\n", pos->ans);
//			if (pos->saved_ans != NULL)
//			{
//			tputs(tgoto(tgetstr("cm", NULL), 0, 3), 1, ft_putchar);
//			printf("pos->saved_ans = %-20.20s/\n", pos->saved_ans);
//			}
//			tputs(tgoto(tgetstr("cm", NULL), 0, 4), 1, ft_putchar);
//			printf("pos->saved_ans = %-d/\n", pos->saved_ans == NULL ? -1 : pos->saved_ans[0]);
//			}
void	print_info(t_pos *pos)
{
	tputs(tgetstr("sc", NULL), 1, ft_putchar);

	if (pos->max_co >= 16)
	{
		clear_info(21);
		
//		tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
//		ft_printf("{S.white.T.grey.}pos->ans  = %-80.80s/{eoc}\n", pos->ans);

		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 0), 1, ft_putchar);
		printf("act_co    = %03d/\n", pos->act_co);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 1), 1, ft_putchar);
		printf("act_li    = %03d/\n", pos->act_li);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 2), 1, ft_putchar);	
		printf("start_co  = %03d/\n", pos->start_co);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 3), 1, ft_putchar);	
		printf("start_li  = %03d/\n", pos->start_li);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 4), 1, ft_putchar);
		printf("max_co    = %03d/\n", pos->max_co);	
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 5), 1, ft_putchar);
		printf("max_li    = %03d/\n", pos->max_li);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 6), 1, ft_putchar);
		printf("let_nb    = %03d/\n", pos->let_nb);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 7), 1, ft_putchar);
		printf("let_nb_sav= %03d/\n", pos->let_nb_saved);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 8), 1, ft_putchar);
		printf("strlen_ans= %03d/\n", ft_strlen(pos->ans));
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 9), 1, ft_putchar);
		printf("len_ans   = %03d/\n", pos->len_ans);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 10), 1, ft_putchar);
		printf("historyMd = %03d/\n", pos->history_mode);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 11), 1, ft_putchar);
		printf("len_prompt= %03d/\n", pos->len_prompt);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 12), 1, ft_putchar);
		printf("is_compl  = %03d/\n", pos->is_complete);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 13), 1, ft_putchar);
		printf("histloop  = %03d/\n", pos->history_loop);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 14), 1, ft_putchar);
		printf("debug     = %03d/\n", pos->debug);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 15), 1, ft_putchar);
		printf("debug2    = %03d/\n", pos->debug2);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 16), 1, ft_putchar);
		printf("start_s   = %03d/\n", pos->start_select);
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 17, 17), 1, ft_putchar);
		printf("debug4    = %03d/\n", pos->debug4);
		tputs(tgoto(tgetstr("cm", NULL), 0, 18), 1, ft_putchar);
		printf("copy    = %s/\n", stock(NULL, 4));
	}
	else if (pos->max_co < 16)
	{
		clear_info(42);
		tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar);
		printf("AC\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, ft_putchar);
		printf("%02d\n", pos->act_co);

		tputs(tgoto(tgetstr("cm", NULL), 0, 2), 1, ft_putchar);
		printf("AL\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 3), 1, ft_putchar);
		printf("%02d\n", pos->act_li);

		tputs(tgoto(tgetstr("cm", NULL), 0, 4), 1, ft_putchar);
		printf("SC\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 5), 1, ft_putchar);	
		printf("%02d\n", pos->start_co);

		tputs(tgoto(tgetstr("cm", NULL), 0, 6), 1, ft_putchar);
		printf("SL\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 7), 1, ft_putchar);	
		printf("%02d\n", pos->start_li);

		tputs(tgoto(tgetstr("cm", NULL), 0, 8), 1, ft_putchar);
		printf("MC\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 9), 1, ft_putchar);
		printf("%02d\n", pos->max_co);

		tputs(tgoto(tgetstr("cm", NULL), 0, 10), 1, ft_putchar);
		printf("ML\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 11), 1, ft_putchar);
		printf("%02d\n", pos->max_li);

		tputs(tgoto(tgetstr("cm", NULL), 0, 12), 1, ft_putchar);
		printf("LE\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 13), 1, ft_putchar);
		printf("%02d\n", pos->let_nb);

		tputs(tgoto(tgetstr("cm", NULL), 0, 14), 1, ft_putchar);
		printf("LS\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 15), 1, ft_putchar);
		printf("%02d\n", pos->let_nb_saved);

		tputs(tgoto(tgetstr("cm", NULL), 0, 16), 1, ft_putchar);
		printf("LN\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 17), 1, ft_putchar);
		printf("%02d\n", ft_strlen(pos->ans));

		tputs(tgoto(tgetstr("cm", NULL), 0, 18), 1, ft_putchar);
		printf("L+\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 19), 1, ft_putchar);
		printf("%02d\n", pos->len_ans);

		tputs(tgoto(tgetstr("cm", NULL), 0, 20), 1, ft_putchar);
		printf("AC\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 21), 1, ft_putchar);
		printf("%02d\n", pos->history_mode);

		tputs(tgoto(tgetstr("cm", NULL), 0, 22), 1, ft_putchar);
		printf("LP\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 23), 1, ft_putchar);
		printf("%02d\n", pos->len_prompt);

		tputs(tgoto(tgetstr("cm", NULL), 0, 24), 1, ft_putchar);
		printf("CO\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 25), 1, ft_putchar);
		printf("%02d\n", pos->is_complete);

		tputs(tgoto(tgetstr("cm", NULL), 0, 26), 1, ft_putchar);
		printf("HL\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 27), 1, ft_putchar);
		printf("%02d\n", pos->history_loop);

		tputs(tgoto(tgetstr("cm", NULL), 0, 28), 1, ft_putchar);
		printf("D1\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 29), 1, ft_putchar);
		printf("%02d\n", pos->debug);

		tputs(tgoto(tgetstr("cm", NULL), 0, 30), 1, ft_putchar);
		printf("D2\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 31), 1, ft_putchar);
		printf("%02d\n", pos->debug2);

		tputs(tgoto(tgetstr("cm", NULL), 0, 32), 1, ft_putchar);
		printf("D3\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 33), 1, ft_putchar);
		printf("%02d\n", pos->debug3);

		tputs(tgoto(tgetstr("cm", NULL), 0, 34), 1, ft_putchar);
		printf("D4\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 35), 1, ft_putchar);
		printf("%02d\n", pos->debug4);

		tputs(tgoto(tgetstr("cm", NULL), 0, 36), 1, ft_putchar);
		printf("D5\n");
		tputs(tgoto(tgetstr("cm", NULL), 0, 37), 1, ft_putchar);
		printf("%02d\n", pos->debug5);
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar);
}
/*
void	print_hist(t_pos *pos, t_hist *hist)
{
	t_hist	*tmp;
	int		i;
	int		actual_hist;

	if (hist == NULL)
		return;
	tmp = hist;
	actual_hist = tmp->cmd_no;
	i = 0;
	while (tmp->prev)
		tmp = tmp->prev;
	tputs(tgetstr("sc", NULL), 1, ft_putchar);
	while (tmp)
	{
		if (i == 20)
			break ;
		tputs(tgoto(tgetstr("cm", NULL), pos->max_co - 77, i), 1, ft_putchar);
		if (actual_hist == tmp->cmd_no)
			ft_printf("cmd[%3d]    = {S.red.T.white.}%-35.35s/\n", i, tmp == NULL ? NULL : tmp->cmd);
		else
			ft_printf("cmd[%3d]    = %-35.35s/\n", i, tmp == NULL ? NULL : tmp->cmd);
		i++;
		tmp = tmp->next;
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar);
}*/

