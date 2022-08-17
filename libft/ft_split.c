/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:33:37 by fothman           #+#    #+#             */
/*   Updated: 2022/07/07 13:15:57 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_str(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && s)
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	ft_word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;
	int		count;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	count = ft_count_str(s, c);
	ans = malloc((count + 1) * sizeof(char *));
	if (!ans)
		return (NULL);
	while (++j < count)
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s, c, i);
		ans[j] = ft_substr(s, i, len);
		i += len;
	}
	ans[j] = 0;
	return (ans);
}
