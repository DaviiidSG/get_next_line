/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserrano <dserrano@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 01:04:40 by dserrano          #+#    #+#             */
/*   Updated: 2026/04/10 01:04:41 by dserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;
	size_t	i;

	if (!(*s))
	{
		dest = malloc(1 * sizeof(*dest));
		if (!dest)
			return (NULL);
		*dest = '\0';
		return (dest);
	}
	s_len = ft_strlen(s);
	dest = malloc((s_len + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= s_len)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

ssize_t	srch_newline_and_len(const char *s, size_t *buff_len)
{
	size_t	i;
	ssize_t	n_pos;

	i = 0;
	n_pos = -1;
	while (s && s[i])
	{
		if (s[i] == '\n' && n_pos == -1)
			n_pos = i;
		i++;
	}
	*buff_len = i;
	return (n_pos);
}

char	*ft_substr(char const *s, unsigned int start, size_t len, size_t s_len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (!s_len || start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		dst = malloc(((s_len - start) + 1) * sizeof(*dst));
	else
		dst = malloc((len + 1) * sizeof(*dst));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2,
	size_t s1_len, size_t s2_len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	str = malloc((s1_len + s2_len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
