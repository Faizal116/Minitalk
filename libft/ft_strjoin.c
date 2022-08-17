/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:42:47 by fothman           #+#    #+#             */
/*   Updated: 2022/07/06 16:13:13 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catted;
	size_t	len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	catted = malloc((len + 1) * sizeof(char));
	if (!catted)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		catted[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		catted[i] = *s2++;
		i++;
	}
	catted[i] = '\0';
	return (catted);
}
