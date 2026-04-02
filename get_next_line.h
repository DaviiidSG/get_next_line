/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:15:49 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/02 14:50:59 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "buffer_size.h"

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
ssize_t	srch_newline(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len, size_t s_len);
char	*ft_strjoin(char const *s1, char const *s2,
			size_t s1_len, size_t s2_len);

#endif
