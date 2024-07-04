/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:20:01 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/05/17 01:00:33 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_dup(const char *str)
{
	size_t		len;
	size_t		i;
	char		*dup;

	len = ft_len(str);
	i = 0;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_sub(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_len(s))
		return (ft_dup(""));
	if (ft_len(s) - start > len)
		size = len;
	else
		size = ft_len(s) - start;
	sub = (char *)malloc(sizeof(char ) * (size + 1));
	if (!sub)
		return (NULL);
	while (i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_chr(const char *str, int c)
{
	unsigned int	i;
	char			cch;

	i = 0;
	cch = c;
	while (str[i])
	{
		if (str[i] == cch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_join(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_len(s1) + ft_len(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
