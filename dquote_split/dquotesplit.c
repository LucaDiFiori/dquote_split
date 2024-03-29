# include "dquotesplit.h"

/**************************IN SPLIT.C****************************************/

/*
Questo split restituisce tutto cio che viene inserito fra apici come unico
elemento. 
(Anche se ho elementi attaccati alle virgolette ad esempio: 
input: 'ciao come'stai 
split: ciao come
       stai
)
*/
int	count_quote(char const *str)
{
	int	dquote;
	int	i;

	dquote = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			dquote++;
	}
	return (dquote);
}

int	skip_quote(const char *str, int i, int flag, int *end_word)
{
	int	dquote;

	dquote = count_quote(str);
	if (flag == 0)
	{
		while (dquote != 0 && str[i])
		{
			if ((str[i] == 34 || str[i] == 39))
				dquote--;
			i++;
		}
	}
	else if (flag == 1)
	{
		while (dquote != 0 && str[i])
		{
			*end_word = *end_word + 1;
			if ((str[i] == 34 || str[i] == 39))
				dquote--;
			i++;
		}
	}
	return (i);
}

static int	count_words(char const *str, char c)
{
	int	count;
	
	count = 0;
	if (count_quote(str) == 1)
		count = normal_count(str, c);
	else 
		count = with_quote_count(str, c);
	printf ("count = %d", count);
	return (count);
}

static void	ft_ret(char **ret, const char *str, t_ssplit *s, char c)
{
	int end_wrd;

	if ((str[s->j] == 34 || str[s->j] == 39) && count_quote(str) != 1
		&& (str[(s->j) - 1] == c || str[(s->j) + 1] == c))
	{
		end_wrd = 0;
		s->j = skip_quote(str, s->j, 1, &end_wrd);
		ret[s->i] = ft_substr(str + ((s->j - end_wrd) + 1), 0, end_wrd - 2);
		s->i = s->i + 1;
	}
	else
	{
		end_wrd = 0;
		while (str[s->j] && str[s->j] != c && ++end_wrd)
			s->j = s->j + 1;
		ret[s->i] = ft_substr(str + (s->j - end_wrd), 0, end_wrd);
		s->i = s->i + 1;
	}
}

char	**dquote_split(char const *str, char c)
{
	t_ssplit	s;
	char		**ret;

	if (!str)
		return (NULL);
	ret = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (ret == NULL)
		return (NULL);
	s.i = 0;
	s.j = 0;
	while (str[s.j])
	{
		if (str[s.j] == c)
			s.j++;
		else
		{
			ft_ret(ret, str, &s, c);
		}
	}
	ret[s.i] = NULL;
	return (ret);
}

/******************************************************************************/

int main(int argc, char **argv)
{
    if (argc >= 1)
    {
        int i;
        char **matrice;

        i = -1;
		printf ("||argv[1] = %s||\n", argv[1]);
        matrice = dquote_split(argv[1], ' ');
		printf("\nDopo lo split: \n");
        while (matrice[++i])
            printf("%s\n", matrice[i]);
    }
    else 
        printf("NO\n");
}