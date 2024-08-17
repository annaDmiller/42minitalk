/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_server.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:27:53 by amelniko          #+#    #+#             */
/*   Updated: 2024/08/17 12:45:17 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_SERVER_H
# define HEADER_SERVER_H
# define _GNU_SOURCE

# include "./../libft/libft.h"
# include "./../libft/ft_printf.h"
# include "./../libft/get_next_line.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_state
{
	int	bit_num;
	int	let;
	int	check_end_mess;
	int	client_pid;
	int	bit;
}		t_state;

extern volatile t_state	*g_state;

void				hdl(int sig, siginfo_t *info, void *context);
struct sigaction	init_sig_logic(void);
void				error_hdl(char *cause);
#endif
