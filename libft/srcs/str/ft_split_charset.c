#include "libft.h"

static int	check_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_str(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !check_separator(str[i], charset))
			i++;
	}
	return (count);
}

static int	ft_strlensep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_separator(str[i], charset))
		i++;
	return (i);
}

static char	*ft_word(char *str, char *charset)
{
	int		len_w;
	int		i;
	char	*word;

	i = 0;
	len_w = ft_strlensep(str, charset);
	word = (char *)malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	while (i < len_w)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_str(str, charset) + 1));
	if (!strings)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, charset))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !check_separator(*str, charset))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
