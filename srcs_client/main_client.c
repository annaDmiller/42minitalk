#include "header_client.h"

struct sigaction    init_sig_logic(void);
void    hdl(int sig);

void    hdl(int sig)
{
    ft_printf("Received the signal\n");
}

int main(int argc, char **argv)
{
    int PID_server;

    if (argc != 3)
        return (ft_putstr_fd("Enter the PID of server and string to print\n", 2), 1);
    PID_server = ft_atoi(*(argv + 1));
    return (0);
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