#include "header_client.h"

void    client_hdl(int sig)
{
    int bit;

    if (sig == SIGUSR1)
        bit = 0;
    else
        bit = 1;
    ft_printf("The big %i received by server\n", bit);
    return ;
}

struct sigaction    init_sig_logic(void)
{
    struct sigaction    act;
    sigset_t            set;

    ft_memset(&act, 0, sizeof(act));
    act.sa_handler = client_hdl;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    act.sa_mask = set;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    return (act);
}
