#include "rush02.h"

int		ft_word_len(int i)
{
	int		len;
	int		fd;
	char	buffer;

	len = 0;
	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
		return (0);
	while (i-- > 0)
		read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) && buffer == ' ')
		;
	read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) && buffer == ' ')
		;
	while (read(fd, &buffer, 1) && buffer != '\n')
		len++;
	return (len);
}

char	*ft_get_word_in_dict(int fd, int nb_char, char buffer)
{
	char	*str;
	int		i;

	i = ft_word_len(nb_char);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (buffer == ' ')
		read(fd, &buffer, 1);
	read(fd, &buffer, 1);
	while (buffer == ' ')
		read(fd, &buffer, 1);
	i = 0;
	while (buffer != '\n')
	{
		str[i] = buffer;
		i++;
		read(fd, &buffer, 1);
	}
	str[i] = '\0';
	return (str);
}

void	ft_go_to_next_line(int *fd, int *i)
{
	char	buffer;

	while (read(*fd, &buffer, 1))
	{
		if (buffer == '\n')
			break ;
	}
	*i = 0;
}

char	*ft_remove_multiple_space(char *str)
{
	char	*str_cpy;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	if (!(str_cpy = (char *)malloc(sizeof(char) * (len + 100))))
		ft_error();
	i = 1;
	j = 1;
	str_cpy[0] = str[0];
	while (str[i])
	{
		if (!(str[i] == ' ' && str[i - 1] == ' '))
		{
			str_cpy[j] = str[i];
			j++;
		}
		i++;
	}
	str_cpy[j] = '\0';
	ft_realloc(&str_cpy, '-');
	return (str_cpy);
}

char	*ft_parse_dict(char *str)
{
	int		fd;
	int		i;
	char	buffer;
	char	*output;

	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
		return (0);
	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (str[i] != buffer && str[i] != '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		if ((buffer == ':' || buffer == ' ') && str[i] == '\0')
			output = ft_get_word_in_dict(fd, i, buffer);
		if (str[i] == '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (ft_remove_multiple_space(output));
}
