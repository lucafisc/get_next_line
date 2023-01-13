/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:32 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/26 20:34:56 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_newline_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*trim_after_newline(char *src)
{
	int		i;
	char	*new_str;
	int		extra;

	if (!src[0])
		return (NULL);
	i = get_newline_index(src);
	extra = 1;
	if (src[i] == '\n')
		extra++;
	new_str = malloc(sizeof(char) * (i + extra));
	if (!new_str)
		return (NULL);
	i = -1;
	while (src[++i] != '\n' && src[i])
		new_str[i] = src[i];
	if (src[i] == '\n')
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*trim_before_newline(char *src)
{
	int		i;
	int		len;
	int		j;
	char	*new_str;

	i = get_newline_index(src);
	if (src[i] == '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	len = ft_strlen(src);
	new_str = malloc(sizeof(char) * (len - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (src[i])
		new_str[j++] = src[i++];
	new_str[j] = '\0';
	free(src);
	return (new_str);
}

char	*read_file(char **stash, int fd)
{
	int		i;
	char	*buff[FOPEN_MAX];

	buff[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff[fd])
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, buff[fd], BUFFER_SIZE);
		if (i < 0)
		{
			free(buff[fd]);
			free(stash[fd]);
			return (NULL);
		}
		buff[fd][i] = '\0';
		stash[fd] = ft_joinnfree(stash[fd], buff[fd]);
		if (ft_strchr(stash[fd]))
			break ;
	}
	free(buff[fd]);
	return (stash[fd]);
}

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!ft_strchr(stash[fd]))
		stash[fd] = read_file(stash, fd);
	if (!stash[fd])
		return (NULL);
	line = trim_after_newline(stash[fd]);
	stash[fd] = trim_before_newline(stash[fd]);
	return (line);
}

