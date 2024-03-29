# include "dquotesplit.h"

int	normal_count(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{	
		while (str[i] == c && str[i])
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

int	with_quote_count(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
		{
			while (str[i] == c && str[i])
				i++;
			if (((str[i] == 39)
				&& (ft_strchar((str + i + 1), 39) != NULL)) && count++)
				i = skip_quote(str, i, 0, NULL);
			else if (((str[i] == 34)
				&& (ft_strchar((str + i + 1), 34) != NULL)) && count++)
				i = skip_quote(str, i, 0, NULL);
			else
			{
				if (str[i] != '\0')
					count++;
				while (str[i] != c && str[i] && (str[i] != 39 && str[i] != 34))
					i++;
			}
		}
	return (count);
}