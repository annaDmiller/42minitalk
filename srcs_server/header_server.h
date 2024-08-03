#ifndef HEADER_SERVER_H
# define HEADER_SERVER_H
# define _GNU_SOURCE
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <unistd.h>
#include <signal.h>

void    hdl(int sig);
struct sigaction    init_sig_logic(void);
#endif