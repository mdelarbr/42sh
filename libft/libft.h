/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:20:22 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 09:20:41 by mjalenqu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);

int					ft_isblank(int c);

int					ft_isalnum(int c);

int					ft_isprint(int c);

int					ft_isdigit(int c);

int					ft_isascii(int c);

int					ft_atoi(const char *str);

char				*ft_itoa(int n);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putsnb(char *s, int n, char *s2);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putstr2(const char *str, char *str2);
void				ft_putcolor(char *c1, char *str, char *c2);
void				ft_putcolor2(char *s, char *s1, char *s2, char *s3);

void				ft_putnbr(int num);
void				ft_putnbr_fd(int n, int fd);

void				ft_putendl(const char *c);
void				ft_putendl_fd(const char *c, int fd);

char				*ft_strstr(const char *str, const char *to_find);

char				*ft_strnstr(const char *str, const char *to_find, int n);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

char				*ft_strdup(const char *src);

char				**ft_strsplit(char const *s, char c);

size_t				ft_strlen(const char *str);
size_t				ft_strclen(const char *str, int c);
size_t				ft_strnclen(const char *str, int c, int n);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t n);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strchr(const char *str, int c);
size_t				ft_strcchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);
void				ft_arrstrdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strfsub(char *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char const *s2);

char				*ft_strtrim(char const *s);

int					ft_tolower(int c);

int					ft_toupper(int c);

void				*ft_memchr(const void *str, int c, size_t n);

void				*ft_memalloc(size_t size);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

int					ft_memcmp(const void *str1, const void *str2, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *s, int c, size_t n);

void				ft_memdel(void **ap);

void				ft_bzero(void *s, size_t n);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstpush(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_lstlen(t_list *lst);

#endif
