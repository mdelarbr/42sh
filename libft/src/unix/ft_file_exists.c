/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file_exists.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mjalenqu <mjalenqu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 14:44:45 by mjalenqu     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 12:23:39 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_unix.h"

int	ft_file_exists(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}
