# include "dquotesplit.h"

int	s_len(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*end_word_dest;
	const unsigned char	*end_word_src;

	end_word_dest = (unsigned char *)dest;
	end_word_src = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		end_word_dest[i] = end_word_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((sizeof(char)) * (s_len(src) + 1));
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*end_word;

	if (!s)
		return (NULL);
	if (len > s_len(s))
		len = s_len(s);
	if (start >= s_len(s))
		return (ft_strdup(""));
	end_word = (char *)malloc((len + 1) * sizeof(char));
	if (end_word == NULL)
		return (NULL);
	ft_memcpy(end_word, s + start, len);
	end_word[len] = '\0';
	return (end_word);
}

const char *ft_strchar(const char *str, const char c)
{
	while(str)
	{
		if(*str == c)
				return(str);
		str++;
	}
	return (NULL);
}

