/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:22:34 by jesopan-          #+#    #+#             */
/*   Updated: 2024/05/04 12:17:40 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *leftover, char *buffer)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftover);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

char	*leftover_from_line(char *line)
{
	char		*leftover;
	ssize_t		len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	if (line[len] == 0 || line[1] == 0)
		return (NULL);
	leftover = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (*leftover == 0)
	{
		free(leftover);
		leftover = NULL;
	}
	len++;
	line[len] = '\0';
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char		*leftover[FD_SIZE];
	char			*line;
	char			*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftover[fd]);
		free(buffer);
		leftover[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_file(fd, leftover[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover[fd] = leftover_from_line(line);
	return (line);
}
