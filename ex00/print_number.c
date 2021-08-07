#include "rush02.h"

char	*ft_cat(char c1, char c2)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 3)))
		return (0);
	str[0] = c1;
	str[1] = c2;
	str[2] = 0;
	return (str);
}

char	*ft_string(char c1)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = c1;
	str[1] = 0;
	return (str);
}

void	print_tab2(char *str)
{
	if (str[0] == '1')
		putstr(ft_parse_dict(ft_cat(str[0], str[1])));
	else
	{
		putstr(ft_parse_dict(ft_cat(str[0], '0')));
		if (str[1] != '0')
		{
			write(1, " ", 1);
			putstr(ft_parse_dict(ft_string(str[1])));
		}
	}
}

void	print_tab3(char *str)
{
	if (str[0] != '0')
	{
		putstr(ft_parse_dict(ft_string(str[0])));
		write(1, " ", 1);
		putstr(ft_parse_dict("100"));
		if (str[1] != '0' || str[2] != '0')
			write(1, " and ", 5);
	}
	if (str[1] != '0' || str[2] != '0')
	{
		if (str[1] == '0')
			putstr(ft_parse_dict(&str[2]));
		else if (str[1] == '1')
			putstr(ft_parse_dict(ft_cat(str[1], str[2])));
		else
		{
			putstr(ft_parse_dict(ft_cat(str[1], '0')));
			if (str[2] != '0')
			{
				write(1, "-", 1);
				putstr(ft_parse_dict(ft_string(str[2])));
			}
		}
	}
}

void	print_number(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	if (len == 1)
		putstr(ft_parse_dict(str));
	else if (len == 2)
		print_tab2(str);
	else
		print_tab3(str);
}
