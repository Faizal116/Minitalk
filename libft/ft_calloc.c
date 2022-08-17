/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:05:42 by fothman           #+#    #+#             */
/*   Updated: 2022/07/07 17:47:52 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*pointer;
	size_t		total;

	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (NULL);
	total = count * size;
	pointer = malloc(total);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, total);
	return (pointer);
}
