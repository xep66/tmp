#include "libft.h"

static int	ft_wordcount(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static	char	*ft_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		j;
	int		start;
	int		wordcount;

	wordcount = ft_wordcount(str, c);
	split = malloc((wordcount + 1) * sizeof(char *));
	if (!split || !str)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < wordcount)
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		split[j] = ft_word(str, start, i);
		if (!split[j])
			return (NULL);
	}
	split[j] = 0;
	return (split);
}
