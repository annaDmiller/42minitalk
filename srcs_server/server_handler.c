/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:24:11 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/15 12:27:37 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_server.h"

void	hdl(int sig, siginfo_t *info, void *context)
{
	int	bit;

	if (!g_state)
		return ;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_state->let = (g_state->let << 1) | bit;
	g_state->bit_num++;
	g_state->client_pid = info->si_pid;
	if (g_state->bit_num == 8)
	{
		if (g_state->let == 0)
			g_state->check_end_mess = 1;
		g_state->bit_num = 0;
	}
	if (context == NULL || context != NULL)
		return ;
	return ;
}

struct sigaction	init_sig_logic(void)
{
	struct sigaction	act;
	sigset_t			set;

	ft_memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = hdl;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	return (act);
}
