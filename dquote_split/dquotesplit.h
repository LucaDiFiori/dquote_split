#ifndef DQUOTESPLIT_H
# define DQUOTESPLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct  s_ssplit
{
    int i;
    int j;
}               t_ssplit;


/*Supersplit_utils*/
int         normal_count(char const *str, char c);
int         with_quote_count(const char *str, char c);
int	        skip_quote(const char *str, int i, int flag, int *end_word);
int     	count_quote(char const *str);

/*minilib*/
int         s_len(const char *s);
void	    *ft_memcpy(void *dest, const void *src, size_t n);
char	    *ft_strdup(const char *src);
char        *ft_substr(char const *s, int start, int len);
const char  *ft_strchar(const char *str, const char c);

#endif