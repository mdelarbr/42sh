/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/03 15:18:39 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 13:10:09 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_int_len_base(int n, int base);
int		ft_isdigit(int n);
int		ft_isxdigit(int n);
void	ft_putnbr(int n);
void	ft_putnbr_base(int n, int base);
void	*ft_voidrev(void *s);
void	ft_voidswap(void *s, void *d);
#endif
