/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:12:44 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/15 12:13:53 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_client.h"

void	bit_handler(int sig)
{
	if (sig == SIGUSR1)
		g_bit_received = 1;
	return ;
}

struct sigaction	bit_received_action(void)
{
	struct sigaction	act;
	sigset_t			set;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = bit_handler;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	act.sa_mask = set;
	return (act);
}

void	mess_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("The message is received by the server\n");
	return ;
}

struct sigaction	mess_received_action(void)
{
	struct sigaction	act;
	sigset_t			set;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = mess_handler;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	return (act);
}
