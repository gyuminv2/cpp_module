#include "get_next_line_bonus.h"

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
	cut_char = ft_calloc(sizeof(char) * (ft_strlen(save) - i + 1), sizeof(char));
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

char	*ft_get_line(char *save)
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

char	*ft_read_save(int fd, char *save)
{
	char	*buff;
	int		bytes;

	if (BUFFER_SIZE == 2147483647)
		buff = ft_calloc(BUFFER_SIZE, sizeof(char));
	else
		buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = 0;
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[10239];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 10240)
		return (NULL);
	save[fd] = ft_read_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_saver(save[fd]);
	return (line);
}

// int main()
// {
// 	int	fd[2];
// 	char	*line;
//     int i = 0;

// 	fd[0] = open("test.txt", O_RDONLY);
//     fd[1] = open("test_2.txt", O_RDONLY);
// 	while ((line = get_next_line(fd[i])) != NULL && i < 2)
// 	{
// 		printf("%s\n", line);
//         if (line == NULL)
//         {
//             close(fd[i]);
//             i++;
//         }
// 	}
// }
