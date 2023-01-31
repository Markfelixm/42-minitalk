/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:07:39 by marmulle          #+#    #+#             */
/*   Updated: 2022/12/20 18:52:54 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	scan_for_newline(char *str)
{
	size_t	cursor;

	if (str == NULL)
		return (0);
	cursor = 0;
	while (str[cursor] != '\0'
		&& str[cursor] != '\n')
		cursor++;
	if (str[cursor] == '\0')
		return (0);
	cursor++;
	return (cursor);
}

char	*get_buffer(int fd)
{
	char	*buffer;
	size_t	read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (free_and_null(buffer));
	buffer[read_bytes] = '\0';
	return (buffer);
}

char	*append_buffer(char *cache, char *buffer)
{
	char	*join;
	size_t	cache_len;
	size_t	buffer_len;
	size_t	cursor;

	cache_len = ft_strlen(cache);
	buffer_len = ft_strlen(buffer);
	join = malloc(sizeof(char) * (cache_len + buffer_len + 1));
	if (!join)
		return (NULL);
	cursor = 0;
	while (cache && cache[cursor])
		*(join++) = cache[cursor++];
	free_and_null(cache);
	cursor = 0;
	while (buffer && buffer[cursor])
		*(join++) = buffer[cursor++];
	free_and_null(buffer);
	*join = '\0';
	join -= cache_len + buffer_len;
	return (join);
}

char	*grab_line(char **cache)
{
	char	*line;
	size_t	line_len;
	size_t	cursor;
	char	*hold;

	line_len = scan_for_newline(*cache);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	cursor = 0;
	while (cursor < line_len)
		*(line++) = (*cache)[cursor++];
	*line = '\0';
	line -= line_len;
	hold = ft_strldup(*cache + line_len, ft_strlen(*cache) - line_len);
	free_and_null(*cache);
	*cache = ft_strldup(hold, ft_strlen(hold));
	free(hold);
	return (line);
}
