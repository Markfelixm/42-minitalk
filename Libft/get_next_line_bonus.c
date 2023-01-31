/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:14:16 by marmulle          #+#    #+#             */
/*   Updated: 2022/12/20 18:54:27 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_and_null(char	*str)
{
	if (!str)
		return (NULL);
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_strldup(const char *str, size_t size)
{
	char	*dup;
	size_t	s_len;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (s_len > size)
		s_len = size;
	dup = (char *)malloc(s_len + 1);
	if (!dup)
		return (NULL);
	while (*str && size-- > 0)
		*(dup++) = *(str++);
	*dup = '\0';
	return (dup - s_len);
}

char	*handle_eof(char **cache)
{
	char	*hold;

	if (*cache && scan_for_newline(*cache) == 0)
	{
		if (ft_strlen(*cache) == 0)
		{
			free (*cache);
			*cache = NULL;
			return (NULL);
		}
		hold = append_buffer(*cache, NULL);
		if (*hold == '\0')
			return (free_and_null(hold));
		*cache = NULL;
		return (hold);
	}
	return (*cache);
}

char	*get_next_line(int fd)
{
	static char	*cache[OPEN_MAX];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!cache[fd])
		cache[fd] = NULL;
	while (1)
	{
		if (scan_for_newline(cache[fd]))
			return (grab_line(&cache[fd]));
		buffer = get_buffer(fd);
		if (buffer == NULL)
		{
			free_and_null(buffer);
			return (handle_eof(&cache[fd]));
		}
		cache[fd] = append_buffer(cache[fd], buffer);
	}
}
