#include "header_server.h"

void    hdl(int sig, siginfo_t *info, void *context)
{
    int         bit;

    if (!point_state)
        return ;
    if (sig == SIGUSR1)
        bit = 0;
    else
        bit = 1;
    point_state->let = (point_state->let << 1) | bit;
    point_state->bit_num++;
    point_state->client_pid = info->si_pid;
    if (point_state->bit_num == 8)
    {
        if (point_state->let == 0)
            point_state->check_end_mess = 1;
        point_state->bit_num = 0;
    }
    if (context == NULL || context != NULL)
        return ;
    return ;
}

struct sigaction    init_sig_logic(void)
{
    struct sigaction    act;
    sigset_t            set;

    ft_memset(&act, 0, sizeof(act));
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = hdl;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    act.sa_mask = set;
    if (sigaction(SIGUSR1, &act, NULL) == -1
        || sigaction(SIGUSR2, &act, NULL) == -1)
        exit (EXIT_FAILURE);
    return (act);
}
