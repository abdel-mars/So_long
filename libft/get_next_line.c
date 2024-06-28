/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:30:50 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/06/28 17:16:55 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_line(char *line_buff)
{
	char		*rest;
	ssize_t		i;

	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == '\0' || line_buff[1] == '\0')
		return (NULL);
	rest = ft_sub(line_buff, i + 1, ft_len(line_buff) - i);
	if (*rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	line_buff[i + 1] = '\0';
	return (rest);
}

static char	*read_line(int fd, char *rest, char *buff)
{
	ssize_t	read_buff;
	char	*tmp;

	read_buff = 1;
	while (read_buff > 0)
	{
		read_buff = read(fd, buff, BUFFER_SIZE);
		if (read_buff == -1)
		{
			free(rest);
			return (NULL);
		}
		else if (read_buff == '\0')
			break ;
		buff[read_buff] = '\0';
		if (!rest)
			rest = ft_dup("");
		tmp = rest;
		rest = ft_join(tmp, buff);
		free (tmp);
		tmp = NULL;
		if (ft_chr(buff, '\n'))
			break ;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		free(rest);
		rest = NULL;
		buff = NULL;
		return (NULL);
	}
	line = read_line(fd, rest, buff);
	free (buff);
	buff = NULL;
	if (!line)
		return (NULL);
	rest = set_line(line);
	return (line);
}
