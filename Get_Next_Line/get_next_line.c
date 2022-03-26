#include "get_next_line.h"

char	*ft_saver(char *save)
{
	int		i;
	int		i2;
	char	*cut_char;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	cut_char = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	if (!cut_char)
		return (NULL);
	i++;
	i2 = 0;
	while (save[i])
		cut_char[i2++] = save[i++];
	cut_char[i2] = '\0';
	free(save);
	return (cut_char);
}

char	*ft_print_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read_join(int fd, char *save)
{
	char	*buffer;
	int		size;

	if (BUFFER_SIZE == 2147483647)
		buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	else
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	size = 1;
	while (size != 0 && !ft_strchr(save, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = ft_read_join(fd, save);
	if (!save)
		return (NULL);
	line = ft_print_line(save);
	save = ft_saver(save);
	return (line);
}
