/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:21:51 by jolopez-          #+#    #+#             */
/*   Updated: 2022/05/08 13:52:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_str_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_str_find_chr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_str_len(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_str_join_buffer(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*sol;

	if (!buffer)
		return (NULL);
	sol = malloc(sizeof(char) * ((ft_str_len(str) + ft_str_len(buffer)) + 2));
	if (sol == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			sol[i] = str[i];
			i++;
		}
	}
	while (buffer[j] != '\0')
		sol[i++] = buffer[j++];
	sol[i] = '\0';
	free(str);
	return (sol);
}
