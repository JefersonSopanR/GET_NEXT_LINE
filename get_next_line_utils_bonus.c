/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:20:35 by jesopan-          #+#    #+#             */
/*   Updated: 2024/05/04 11:23:08 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	str;

	str = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == str)
			return ((char *) s);
		s++;
	}
	if (!str)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
		c++;
	}
	return (c);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	len = ft_strlen(s1) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	i = 0;
	if (new_str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	all_size;
	char			*result;

	i = 0;
	all_size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(all_size + 1);
	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		else if (s2)
			return (ft_strdup(s2));
		else
			return (ft_strdup(""));
	}
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (s == NULL || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
