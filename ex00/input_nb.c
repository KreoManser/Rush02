#include "rush02.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		ft_realloc(char **str, char sign)
{
	int		len;
	char	*str_cpy;

	len = ft_strlen(*str);
	if (sign == '+')
	{
		if (!(str_cpy = (char *)malloc(sizeof(char) * (len + 100))))
			exit(0);
		ft_strncpy(str_cpy, *str, len + 1);
		free(*str);
		*str = str_cpy;
	}
	else
	{
		if (!(str_cpy = (char *)malloc(sizeof(char) * len)))
			exit(0);
		ft_strncpy(str_cpy, *str, len + 1);
		free(*str);
		*str = str_cpy;
	}
	return (1);
}

char	*get_nb_from_pipe(void)
{
	char	*str;
	char	buffer;
	int		i;
	int		j;

	if (!(str = (char *)malloc(sizeof(char) * 100)))
		return (0);
	i = 0;
	j = 99;
	while (j == 99)
	{
		j = -1;
		while (read(STDIN_FILENO, &buffer, 1) > 0 && ++j < 99)
			str[i++] = buffer;
		if (i == 0)
			return (0);
		str[i] = '\0';
		if (j < 99)
			ft_realloc(&str, '-');
		else
			ft_realloc(&str, '+');
	}
	str[--i] = '\0';
	return (str);
}
