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

#include "get_next_line.h"

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
	size_t		len;
	char		*new_str;
	size_t		i;

	len = get_newline_index(src);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		new_str[i] = src[i];
		i++;
	}
	return (new_str);
}

char	*trim_before_newline(char *src)
{
	int		start;
	int		i;
	int		len;
	char	*new_str;

	start = get_newline_index(src) + 1;
	len = ft_strlen(src) - start;
	if (len <= 0)
		new_str = NULL;
	else
	{	
		new_str = malloc(sizeof(char) * (len));
		if (!new_str)
			return (NULL);
		i = 0;
		while (i < len)
		{
			new_str[i] = src[start + i];
			i++;
		}
	}
	free(src);
	return (new_str);
}

char	*read_file(char *stash, int fd)
{
	int		i;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE))
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n'))
			break;
	}
	free(buff);
	if (i >= 0)
		return (stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(stash, fd);
	if (!stash)
		return (NULL);
	line = trim_after_newline(stash);
	stash = trim_before_newline(stash);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *pt;
// 	fd = open("files/only_nl.txt", O_RDONLY);
// 	if (fd == -1)
// 			write(2, "error opening file", 18);
// 	pt = get_next_line(fd);
// 	printf("%s", pt);
// 	free(pt);
// }
