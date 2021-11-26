/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:46:01 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/26 04:40:39 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		new[i++] = s2[j++];
	if (s2[j] == '\n')
	{
		new[i] = '\n';
		new[i + 1] = 0;
	}
	else
		new[i] = 0;
	free(s1);
	return (new);
}

char	*ft_set_mem(char *buff, char *mem)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	mem = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (!mem)
		return (NULL);
	while (i < BUFFER_SIZE && buff[i])
	{
		mem[j] = buff[i];
		i++;
		j++;
	}
	mem[j] = 0;
	return (mem);
}
