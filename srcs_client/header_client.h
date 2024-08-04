#ifndef HEADER_CLIENT_H
# define HEADER_CLIENT_H
# define _GNU_SOURCE
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <signal.h>

extern int bit_received;

void    bit_handler(int sig);
struct sigaction    bit_received_action(void);
void    mess_handler(int sig);
struct sigaction    mess_received_action(void);

void    send_letter(char let, int pid_server);
void    sending_the_message(char *str, int pid_server);
#endif