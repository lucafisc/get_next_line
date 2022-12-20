/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:32 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/20 15:49:40 by lde-ross         ###   ########.fr       */
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
	int		len;
	char	*new_str;
	int		i;
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
	new_str[i] = '\0';
	return (new_str);
}

char *trim_before_newline(char *src)
{
	int	start;
	int i;
	int len;
	char *new_str;

	start = get_newline_index(src) + 1;
	len = ft_strlen(src) - start;
	new_str = malloc(sizeof(char) * (len));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = src[start + i];
		i++;
	}
	free(src);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (!stash)
			stash = ft_strdup(buff);
		else
			stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n'))
			break;
	}
	if (i < 0 || (i == 0 && !stash))
		return (NULL);
	else
	{
		line = trim_after_newline(stash);
		stash = trim_before_newline(stash);
		return (line);
	}
		return (NULL);
}

int	main(void)
{
	int	fd;
	fd = open("files/41_with_nl", O_RDONLY);
	if (fd == -1)
			write(2, "error opening file", 18);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
