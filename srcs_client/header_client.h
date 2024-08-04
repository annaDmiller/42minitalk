#ifndef HEADER_CLIENT_H
# define HEADER_CLIENT_H
# define _GNU_SOURCE
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <signal.h>

void    client_hdl(int sig);
struct sigaction    init_sig_logic(void);
void    send_letter(char let, int pid_server);
void    sending_the_message(char *str, int pid_server);
#endif