/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:12:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/07 15:48:37 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *leftover)
{
	int		read_elements;
	char	*temp;

	read_elements = read(fd, buffer, BUFFER_SIZE);
	while (read_elements > 0)
	{
		buffer[read_elements] = '\0';
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(leftover, '\n'))
			break ;
		read_elements = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_elements == 0 && (!leftover || leftover[0] == '\0'))
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	return (leftover);
}

char	*divide_line(char **leftover)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while ((*leftover)[i] && (*leftover)[i] != '\n')
		i++;
	temp = *leftover;
	line = ft_substr(temp, 0, i + 1);
	*leftover = ft_substr(temp, i + 1, ft_strlen(temp));
	free(temp);
	if (*leftover && (*leftover)[0] == '\0')
	{
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	if (!leftover)
		leftover = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	leftover = read_line(fd, buffer, leftover);
	free(buffer);
	if (!leftover)
		return (NULL);
	line = divide_line(&leftover);
	return (line);
}
