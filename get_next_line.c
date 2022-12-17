/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:32 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/16 21:17:02 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*str;
	char	pt[1];
	int		i;

	i = 0;

	while (read(fd, pt, 1))
	{
		if (pt[0] == '\n')
		{
			buff[i] = pt[0];
			str = buff;
			return (str);
		}
		buff[i] = pt[0];
		i++;
	}
	close(fd);
	str = buff;
	return (str);

}

// int	main(void)
// {
// 	int	fd;
// 	int	i;
	

// 	fd = open("files/41_no_nl", O_RDONLY);
// 	if (fd == -1)
// 			write(2, "error opening file", 18);
			
// 		printf("%s", get_next_line(fd));
	
	
// }