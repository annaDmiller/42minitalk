/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:17:03 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/15 12:23:30 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_client.h"

volatile int	g_bit_received;

static void	sending_the_message(char *str, int pid_server);
static void	send_letter(char let, int pid_server);

static void	send_letter(char let, int pid_server)
{
	int	num_bit;
	int	bit;

	num_bit = 0;
	while (num_bit < 8)
	{
		g_bit_received = 0;
		bit = (let >> (7 - num_bit)) & 1;
		if (bit == 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		while (!g_bit_received)
			pause();
		num_bit++;
	}
	return ;
}

static void	sending_the_message(char *str, int pid_server)
{
	size_t	len_mes;
	size_t	num_let;

	len_mes = ft_strlen(str);
	num_let = 0;
	while (num_let <= len_mes)
	{
		send_letter(str[num_let], pid_server);
		num_let++;
	}
	g_bit_received = 0;
	return ;
}

int	main(int argc, char **argv)
{
	int					pid_server;
	struct sigaction	bit_rec;
	struct sigaction	full_mess_rec;

	if (argc != 3)
		return (ft_putstr_fd("Enter the PID of server and string to print\n",
				2), 1);
	bit_rec = bit_received_action();
	sigaction(SIGUSR1, &bit_rec, NULL);
	full_mess_rec = mess_received_action();
	sigaction(SIGUSR2, &full_mess_rec, NULL);
	g_bit_received = 0;
	pid_server = ft_atoi(*(argv + 1));
	sending_the_message(*(argv + 2), pid_server);
	return (0);
}
