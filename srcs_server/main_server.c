#include "header_server.h"

struct sigaction    init_sig_logic(void);
void    hdl(int sig);

void    hdl(int sig)
{
    ft_printf("Received the signal\n");
}

int main(void)
{
    struct sigaction    act;
    unsigned int        check;

    check = 0;
    act = init_sig_logic();
    ft_printf("%i\n", getpid());
    while(check == 0)
    {
        pause();
    }
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