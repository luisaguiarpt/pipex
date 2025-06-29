/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:55:17 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 17:23:03 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_slist
{
	void			*content;
	struct s_slist	*next;
}					t_slist;

int			ft_abs(int n);
double		ft_abs_dbl(double n);
double		ft_atod(char *str);
int			ft_atoi(const char *str);
long int	ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isdouble(char *str);
int			ft_isint(char *str);
int			ft_isprint(int c);
char		*ft_itoa(int n);
int			ft_max(int a, int b);
int			ft_max_dbl(double a, double b);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
int			ft_sqrt(int nb);
int			ft_sqrt_approx(int nb);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *str);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);

t_slist		*ft_lstnew(void *content);
void		ft_lstadd_front(t_slist **lst, t_slist *new);
int			ft_lstsize(t_slist *lst);
t_slist		*ft_lstlast(t_slist *lst);
void		ft_lstadd_back(t_slist **lst, t_slist *new);
void		ft_lstdelone(t_slist *lst, void (*del)(void *));
void		ft_lstclear(t_slist **lst, void (*del)(void *));
void		ft_lstiter(t_slist *lst, void (*f)(void *));
t_slist		*ft_lstmap(t_slist *lst, void *(*f)(void *), void (*del)(void *));

#endif
