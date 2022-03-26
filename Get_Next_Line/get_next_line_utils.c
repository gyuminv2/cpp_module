#include "get_next_line.h"

void	ft_memset(void *b, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (!count || !size)
		return (NULL);
	p = malloc(count * size);
	ft_memset(p, count * size);
	return (p);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*str != (char)c && *str != 0)
		str++;
	if (*str == (char)c)
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*save;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	save = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!save)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		save[j++] = s1[i];
	i = -1;
	while (s2[++i])
		save[j++] = s2[i];
	save[j] = 0;
	free(s1);
	return (save);
}
