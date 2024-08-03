#include "header_server.h"

void    hdl(int sig)
{
    ft_printf("Received the signal\n");
}

struct sigaction    init_sig_logic(void)
{
    struct sigaction    act;
    sigset_t            set;

    ft_memset(&act, 0, sizeof(act));
    act.sa_handler = hdl;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    act.sa_mask = set;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    return (act);
}