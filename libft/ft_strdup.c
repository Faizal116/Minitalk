/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:35:03 by fothman           #+#    #+#             */
/*   Updated: 2022/07/06 17:10:01 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	size_t	length;

	length = ft_strlen(s1) + 1;
	pointer = malloc((length) * sizeof(char));
	if (!pointer)
		return (NULL);
	ft_memcpy(pointer, s1, length);
	return (pointer);
}
