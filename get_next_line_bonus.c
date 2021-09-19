#include "get_next_line_bonus.h"

char	*save_buffer(char **mem, char *buf);
char	*gnl_all_free(char **mem, char **buf, char **line, int flag);
char	*get_new_line(char **mem, char **line, char **buf);
char	*get_last_line(char **mem, char **line, char **buf);

char	*get_next_line(int fd)
{
	int			offset;
	char		*buf;
	char		*line;
	static char	*backup[OPEN_MAX + 1];

	buf = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE < 1 || !buf)
		return (gnl_all_free(&backup[fd], &buf, &line, ERROR));
	while (1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset <= 0)
			break ;
		buf[offset] = '\0';
		if (!save_buffer(&backup[fd], buf))
			return (gnl_all_free(&backup[fd], &buf, &line, ERROR));
		if (ft_strchr(backup[fd], '\n') != -1)
			return (get_new_line(&backup[fd], &line, &buf));
	}
	if (offset < 0)
	{
		return (gnl_all_free(&backup[fd], &buf, &line, ERROR));
	}
	return (get_last_line(&backup[fd], &line, &buf));
}

char	*save_buffer(char **backup, char *buf)
{
	char	*tmp;

	if (*backup == 0)
		*backup = ft_strdup(buf);
	else
	{
		tmp = *backup;
		*backup = ft_strjoin(*backup, buf);
		free(tmp);
	}
	return (*backup);
}

char	*get_new_line(char **backup, char **line, char **buf)
{
	char	*tmp;
	int		offset;

	offset = ft_strchr(*backup, '\n') + 1;
	*line = (char *)malloc(offset + 1);
	if (!*line || ft_strlcpy(*line, *backup, offset + 1) == -1)
		return (gnl_all_free(backup, buf, line, ERROR));
	tmp = *backup;
	*backup = ft_strdup(*backup + offset);
	free(tmp);
	tmp = NULL;
	return (gnl_all_free(backup, buf, line, SUCCESS));
}

char	*gnl_all_free(char **backup, char **buf, char **line, int flag)
{
	free(*buf);
	*buf = NULL;
	if (flag == ERROR || flag == END)
	{
		if (flag == END)
		{
			free(*backup);
			*backup = NULL;
		}
		free(*line);
		*line = NULL;
	}
	return (*line);
}

char	*get_last_line(char **backup, char **line, char **buf)
{
	int	offset;

	if (!*backup || !**backup)
		return (gnl_all_free(backup, buf, line, END));
	if (ft_strchr(*backup, '\n') != -1)
		return (get_new_line(backup, line, buf));
	offset = ft_strchr(*backup, '\0');
	*line = (char *)malloc(offset + 1);
	if (!*line || ft_strlcpy(*line, *backup, offset + 1) == -1)
		return (gnl_all_free(backup, buf, line, ERROR));
	free(*backup);
	*backup = NULL;
	return (gnl_all_free(backup, buf, line, SUCCESS));
}
