/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:32:34 by walethea          #+#    #+#             */
/*   Updated: 2020/11/26 23:32:35 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*check_remainder(char	**remainder, char	**line)
{
	char	*p_n;

	p_n = NULL;
	if (*remainder)
	{
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			*line = *remainder;
			*remainder = ft_strdup(++p_n);
		}
		else
		{
			*line = *remainder;
			*remainder = NULL;
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int     get_next_line(int fd, char  **line)
{
	char			*buf;	
	int				count;
	char			*p_n;
	char			*tmp;
	static char		*remainder;

	p_n = NULL;
	count = 0;
	if (!fd || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (remainder)
		p_n = check_remainder(&remainder, line);
	while(!p_n && (count = read(fd, &buf, BUFFER_SIZE)))
	{
		buf[count] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			remainder = ft_strdup(++p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	free(buf);
	return (1);
}

int main()
{
	int     fd;
	int     i;
	char    *line;
	fd = open("text", O_RDONLY);

	// get_next_line(fd ,&line);
	// printf("%s\n", line);

	// get_next_line(fd ,&line);
	// printf("%s\n", line);

	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n  %d\n", line, i);
		free(line);
	}
	close(fd);
}