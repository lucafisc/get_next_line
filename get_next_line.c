/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:32 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/20 11:02:29 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_n_position(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*get_til_n(char *src)
{
	int		len;
	char	*str;
	int		i;
	len = get_n_position(src);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

char *cleanup(char *src)
{
	int	i;
	int j;
	int size;
	char *str;


	i = get_n_position(src) + 1;
	size = ft_strlen(src) - i;
	str = malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	j = 0;
	while (size)
	{
		str[j] = src[i];
		size--;
		i++;
		j++;
	}
	free(src);
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	int r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = (NULL);
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0 && !stash[0])
			return (NULL);
		buff[r] = '\0';
		if (!stash)
			stash = ft_strdup(buff);
		else
			stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n'))
		{
			line = get_til_n(stash);
			stash = cleanup(stash);
			return (line);
		}
	}
	return (NULL);
}

int	main(void)
{
	int	fd;
	fd = open("files/41_no_nl", O_RDONLY);
	if (fd == -1)
			write(2, "error opening file", 18);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
