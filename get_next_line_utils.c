#include "get_next_line.h"

int	ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (d_size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (src[i] != '\0' && i < (d_size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sindex1;
	size_t	sindex2;
	size_t	index;
	size_t	strindex;
	char	*str;

	sindex1 = ft_strlen(s1);
	sindex2 = ft_strlen(s2);
	index = 0;
	strindex = 0;
	str = (char *)malloc(sizeof(char) * (sindex1 + sindex2 + 1));
	if (!str)
		return (NULL);
	while (index < sindex1)
		str[strindex++] = s1[index++];
	index = 0;
	while (index < sindex2)
		str[strindex++] = s2[index++];
	str[strindex] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (i);
	return (-1);
}
