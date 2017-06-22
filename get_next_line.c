#include "get_next_line.h"
#include <stdio.h>

int		ft_getlend(char *data)
{
	int	i;

	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == '\n')
			return(i);
		i++;
	}
	return(ft_strlen(data));
}

int		ft_readbuff(int fd, char *data)
{
	int		bytesr;

	bytesr = 0;
	bytesr = read(fd, data, BUFF_SIZE);
	if (bytesr == 0)
		return (-1);
	if (bytesr > 0)
	{
		data[bytesr + 1] = '\0';
		return (bytesr);
	}
}

int			ft_datafill(char *data, int lend)
{
	int		i;
	char	*temp;

	temp = data;
	lend++;
	while (temp[lend])
	{
		data[i] = temp[lend];
		lend++;
		i++;
	}
	data[i] = temp[lend];
	return (0);
}

char		*ft_realloc(char *line, char *data)
{
	char 	*temp;
	int		i;

	temp = line;
	i = ft_strlen(line) + ft_strlen(data);
	line = (char*)malloc(sizeof(char) * i);
	if (line == NULL)
		return (NULL);
	line = ft_strjoin(line, temp);
	line = ft_strjoin(line, data);
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char	data[BUFF_SIZE + 1];
	int			bytesr;
	int			lend;
	int			i;

	if (fd < 0)
		return (-1);
			if ((lend = ft_getlend(data)) < BUFF_SIZE + 1)
	{
		if (lend < ft_strlen(data))
			ft_datafill(data, lend);
		if ((lend = ft_getlend(data)) < ft_strlen(data))
		{
			*line = ft_realloc(*line, ft_strsub(data, 0, lend));
			ft_datafill(data, lend);
			return (1);
		}
		lend = BUFF_SIZE;
		*line = ft_realloc(*line, data);
	}
	while (lend == BUFF_SIZE)
	{
		bytesr = ft_readbuff(fd, data);
		if (bytesr == -1)
		{
			lend = (int)ft_strlen(data);
			*line = ft_realloc(*line, ft_strsub(data, lend, ft_strlen(data)));
			return (0);
		}
		if ((lend = ft_getlend(data)) == BUFF_SIZE)
			*line = ft_realloc(*line, data);
	}
	*line = ft_realloc(*line, ft_strsub(data, 0, lend));
	return (1);
}
