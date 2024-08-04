#ifndef HEADER_SERVER_H
# define HEADER_SERVER_H
# define _GNU_SOURCE
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <unistd.h>
#include <signal.h>

extern char buff_server[50];

void    hdl(int sig, siginfo_t *info, void *context);
struct sigaction    init_sig_logic(void);

void    print_buff_and_nl(void);
void    check_is_buff_full(void);
void    add_let_to_buff(char let);
#endif