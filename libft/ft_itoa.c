/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:30:49 by fothman           #+#    #+#             */
/*   Updated: 2022/07/07 16:06:14 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*asc;
	size_t		digit;
	long int	num;

	num = n;
	digit = count_digits(n);
	if (n < 0)
	{
		num *= -1;
		digit++;
	}
	if (n == 0)
		return (ft_strdup("0"));
	asc = malloc(sizeof(char) * (digit + 1));
	if (!asc)
		return (NULL);
	*(asc + digit) = 0;
	while (digit--)
	{
		*(asc + digit) = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		*(asc + 0) = '-';
	return (asc);
}
