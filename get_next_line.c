/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:12:02 by dserrano          #+#    #+#             */
/*   Updated: 2026/03/21 14:16:48 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*del_line(char *buff, ssize_t limit)
{
	char	*new_buff;

	new_buff = ft_substr(buff, limit + 1, ft_strlen(buff) - limit - 1);
	free(buff);
	if (!new_buff)
		return (NULL);
	return (new_buff);
}

static char	*ret_line(char **buff, ssize_t n_pos, int isend)
{
	char	*line;

	if (isend)
	{
		line = ft_strdup(*buff);
		free(*buff);
		*buff = NULL;
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_substr(*buff, 0, n_pos + 1);
		if (!line)
			return (NULL);
		*buff = del_line(*buff, n_pos);
		if (!(*buff))
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

static int	free_all(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (-1);
}

static int	read_and_append(int fd, char **buff)
{
	char		*temp_buff;
	char		*temp_join;
	ssize_t		bytes;

	temp_buff = malloc((BUFFER_SIZE + 1) * sizeof(*temp_buff));
	if (!temp_buff)
		return (free_all(*buff, NULL));
	bytes = read(fd, temp_buff, BUFFER_SIZE);
	if (-1 == bytes || (!bytes && !(**buff)))
		return (free_all(*buff, temp_buff));
	else if (!bytes && **buff)
		return (free(temp_buff), 1);
	temp_buff[bytes] = '\0';
	temp_join = ft_strjoin(*buff, temp_buff);
	free_all(*buff, temp_buff);
	if (!temp_join)
		return (-1);
	*buff = temp_join;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	ssize_t		newline_pos;
	int			err_flag;

	if (fd < 0)
		return (NULL);
	if (!static_buff)
	{
		static_buff = ft_strdup("");
		if (!static_buff)
			return (NULL);
	}
	newline_pos = srch_newline(static_buff);
	while (-1 == newline_pos)
	{
		err_flag = read_and_append(fd, &static_buff);
		if (-1 == err_flag)
			return (NULL);
		else if (err_flag)
			return (ret_line(&static_buff, newline_pos, 1));
		newline_pos = srch_newline(static_buff);
	}
	return (ret_line(&static_buff, newline_pos, 0));
}
