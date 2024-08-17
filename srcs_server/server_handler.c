/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:24:11 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/17 13:30:12 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_server.h"

void	hdl(int sig, siginfo_t *info, void *context)
{
	if (!g_state)
		return ;
	if (sig == SIGUSR1)
		g_state->bit = 0;
	else
		g_state->bit = 1;
	g_state->client_pid = info->si_pid;
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
