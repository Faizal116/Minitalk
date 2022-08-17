/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:16:48 by fothman           #+#    #+#             */
/*   Updated: 2022/08/17 23:16:50 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

static void	binary_sending(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

static void	kill_them(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		binary_sending(pid, string[i]);
		i++;
	}
	binary_sending(pid, 0);
}

static void	received_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Message received!\n", 1);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	waffle_sig;

	if (ac == 2)
	{
		ft_putstr_fd("Maybe enter a message?", 1);
		exit (EXIT_FAILURE);
	}
	else if (ac == 3)
	{
		ft_putstr_fd("Sent: ", 1);
		ft_putnbr_fd(ft_strlen(av[2]), 1);
		ft_putchar_fd('\n', 1);
		waffle_sig.sa_handler = received_signal;
		sigaction(SIGUSR1, &waffle_sig, NULL);
		sigaction(SIGUSR2, &waffle_sig, NULL);
		kill_them(ft_atoi(av[1]), av[2]);
		return (0);
	}
}
