/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:13:26 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/26 16:31:06 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		len;
	char	*pt;
	int		i;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	pt = malloc(sizeof(char) * len);
	if (!pt)
		return (0);
	i = 0;
	while (*s1)
	{
		pt[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		pt[i] = *s2;
		i++;
		s2++;
	}
	pt[i] = '\0';
	return (pt);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*pt;
	int		i;

	len = ft_strlen(s1) + 1;
	pt = malloc(sizeof(char) * len);
	if (!pt)
		return (0);
	i = 0;
	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
