/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_client.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:14:19 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/17 12:43:11 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_CLIENT_H
# define HEADER_CLIENT_H
# define _GNU_SOURCE

# include "./../libft/libft.h"
# include "./../libft/ft_printf.h"
# include "./../libft/get_next_line.h"
# include <signal.h>

extern volatile int	g_signal_received;

void				bit_handler(int sig);
struct sigaction	bit_received_action(void);
void				mess_handler(int sig);
struct sigaction	mess_received_action(void);
void				error_hdl(char *cause);
#endif
