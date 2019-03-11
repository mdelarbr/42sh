/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/03 15:18:39 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 15:14:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(void *elem, int i);
void	ft_isalpha(int c);
void	ft_isascii(int c);
char	*ft_itoa(int i);
char	*ft_itoa_base(int nb, int base);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putstr_tab(char **tab);
char	*ft_strcat(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *str);
void	ft_strdel(char **str);
char	*ft_strdup(char *str);
int		ft_strequ(const char *s1, const char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_strjoin_free(char **s1, const char *s2);
void	ft_strjoin_insert(char **s1, char *s2, int i);
int		ft_strlen(const char *str);
char	*ft_strnew(int size);
char	*ft_strrmvi(char *str, int i);
char	*ft_strstr(const char *str, const char *tofind);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	*ft_voidrev(void *s);
void	ft_voidswap(void *s, void *d);
#endif
