/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:35:11 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/06 12:19:57 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen2(const char *str, char c, size_t i)
{
	int	init;

	init = i;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i - init);
}

static int	ft_countWords(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (!s)
		return (0);
	if (s[0] != c)
		w++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			w++;
		i++;
	}
	if (w == 0)
		return (1);
	return (w);
}

static char	*ft_putWord(char const *s, int *i, char c)
{
	int		j;
	char	*str;
	int		l;

	l = ft_strlen2(s, c, *i);
	j = 0;
	str = (char *)malloc((1 + l) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j++] = s[*i];
		*i += 1;
	}
	str[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**strsplit;

	i = 0;
	j = 0;
	words = ft_countWords(s, c);
	if (!s)
		return (NULL);
	strsplit = (char **)malloc((words + 1) * sizeof(char *));
	if (!strsplit)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < words && s[i])
	{
		strsplit[j] = ft_putWord(s, &i, c);
		j++;
	}
	strsplit[j] = NULL;
	return (strsplit);
}
