#ifndef HEADER_CLIENT_H
# define HEADER_CLIENT_H
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <signal.h>

void    hdl(int sig);
struct sigaction    init_sig_logic(void);

#endif