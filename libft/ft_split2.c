#include "libft.h"

static int	ft_nbr_word(const char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			len++;
		}
		i++;
	}
	return (len + 1);
}

char	**ft_split2(char const *s, char c)
{
	int		i;
	int		j;
	int		tmp;
	char	**tab;

	i = 0;
	tmp = 0;
	j = 0;
	if (!s)
		return (0);
	tab = ft_calloc(sizeof(char *), ft_nbr_word(s, c) + 1);
	while (s[i] != '\0' && tab)
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			tmp = i;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (tmp != i)
			tab[j++] = ft_substr(s, tmp, i - tmp);
	}
	return (tab);
}