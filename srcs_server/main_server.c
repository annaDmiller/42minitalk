/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:31:47 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/15 12:35:49 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_server.h"

volatile t_state	*g_state;

static void	print_messages(void);
static void	init_state(t_state *state);

int	main(void)
{
	struct sigaction	act;
	t_state				state;

	init_state(&state);
	act = init_sig_logic();
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		error_hdl("sigaction");
	ft_printf("%i\n", getpid());
	print_messages();
	return (0);
}

static void	print_messages(void)
{
	while (1)
	{
		if (g_state->bit_num == 0 && g_state->client_pid != 0)
		{
			if (g_state->check_end_mess == 1)
			{
				ft_printf("\n");
				g_state->check_end_mess = 0;
				if (kill(g_state->client_pid, SIGUSR2) == -1)
					error_hdl("kill");
				g_state->client_pid = 0;
			}
			else if (g_state->let != 0)
				ft_printf("%c", g_state->let);
			g_state->let = 0;
		}
		if (g_state->client_pid != 0)
		{
			if (kill(g_state->client_pid, SIGUSR1) == -1)
				error_hdl("kill");
		}
		usleep(250);
	}
	return ;
}

static void	init_state(t_state *state)
{
	state->let = 0;
	state->bit_num = 0;
	state->client_pid = 0;
	state->check_end_mess = 0;
	g_state = state;
	return ;
}
