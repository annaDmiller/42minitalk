#ifndef HEADER_SERVER_H
# define HEADER_SERVER_H
# define _GNU_SOURCE
#include "./../libft/libft.h"
#include "./../libft/ft_printf.h"
#include "./../libft/get_next_line.h"
#include <unistd.h>
#include <signal.h>

typedef struct  s_state
{
    int bit_num;
    int let;
    int check_end_mess;
    int client_pid;
}       t_state;

extern volatile t_state *point_state;

void    hdl(int sig, siginfo_t *info, void *context);
struct sigaction    init_sig_logic(void);
void    init_state(t_state *state);
#endif