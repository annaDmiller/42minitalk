#include "header_client.h"

void    bit_handler(int sig)
{
    bit_received = 1;
    return ;
}

struct sigaction    bit_received_action(void)
{
    struct sigaction    act;
    sigset_t            set;

    ft_memset(&act, 0, sizeof(act));
    act.sa_handler = bit_handler;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    act.sa_mask = set;
    sigaction(SIGUSR1, &act, NULL);
    return (act);
}

void    mess_handler(int sig)
{
    ft_printf("The message is received by the server\n");
    return ;
}

struct sigaction    mess_received_action(void)
{
    struct sigaction    act;
    sigset_t            set;

    ft_memset(&act, 0, sizeof(act));
    act.sa_handler = mess_handler;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR2);
    act.sa_mask = set;
    sigaction(SIGUSR2, &act, NULL);
    return (act);
}
