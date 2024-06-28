/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:18:35 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/06/28 17:18:40 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <strings.h>

/*....................libft...................*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

/*....................get_next_line.................*/

size_t	ft_len(const char *str);
char	*ft_dup(const char *str);
char	*ft_sub(char *s, unsigned int start, size_t len);
char	*ft_chr(const char *str, int c);
char	*ft_join(char *s1, char *s2);
char	*get_next_line(int fd);
// char	*read_line(int fd, char *rest, char *buff);
// char	*set_line(char *line_buff);

/*.....................print_f..................*/

int		ft_printf(const char *format, ...);
void	ft_char(char c, int *len);
void	ft_str(char *str, int *len);
void	ft_uint(unsigned int n, int *len);
void	ft_int(int n, int *len);
void	ft_hex(unsigned int n, char x, int *len);
void	ft_check(va_list list, char format, int *len);
void	ft_ptr(unsigned long n, int *len);
void	ft_printadress(unsigned long n, int *len);

#endif
