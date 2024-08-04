#ifndef HEADER_SERVER_H
# define HEADER_SERVER_H
# define _GNU_SOURCE
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <unistd.h>
#include <signal.h>

char buff[1024];

void    hdl(int sig);
struct sigaction    init_sig_logic(void);

void    print_buff_and_nl(void);
void    check_is_buff_full(void);
void    add_let_to_buff(char let);
#endif