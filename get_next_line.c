/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:29:30 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/26 04:40:49 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_mem(char *mem)
{
	char	*mem2;

	while (*mem && *mem != '\n')
		mem++;
	if (*mem == '\n')
		mem++;
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	if (memory)
	{
		line = ft_strjoin(line, memory);
		if (ft_strchr(memory, '\n'))
		{
			memory = ft_update_mem(memory);
			return (line);
		}
	}
	while (read(fd, buff, BUFFER_SIZE) > 0 && !ft_strchr(buff, '\n'))
		line = ft_strjoin(line, buff);
	if (ft_strchr(buff, '\n'))
	{
		memory = ft_set_mem(buff, memory);
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}
