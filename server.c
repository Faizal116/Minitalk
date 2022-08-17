/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:16:55 by fothman           #+#    #+#             */
/*   Updated: 2022/08/17 23:16:56 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	waffle_handling(int sig, siginfo_t *info, void *context)
{
	static int	i;
	int			bit;
	static int	c;

	(void)context;
	if (sig == SIGUSR2)
		bit = 0;
	else
		bit = 1;
	c += (bit << i);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	waffle_sig;

	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	waffle_sig.sa_sigaction = waffle_handling;
	waffle_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &waffle_sig, 0);
	sigaction(SIGUSR2, &waffle_sig, 0);
	while (1)
		pause();
	return (0);
}
