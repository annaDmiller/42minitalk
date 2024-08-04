#include "header_server.h"

void    hdl(int sig, siginfo_t *info, void *context)
{
    static int  bit_num;
    static int  num_let;
    int         bit;

    if (sig == SIGUSR1)
        bit = 0;
    else
        bit = 1;
    num_let = (num_let << 1) | bit;
    bit_num++;
    if (bit_num == 8)
    {
        bit_num = 0;
        if (num_let == 0)
        {
            ft_printf("\n");
            kill(info->si_pid, SIGUSR2);
        }
        else
            ft_printf("%c", num_let);
        num_let = 0;
    }
    kill(info->si_pid, SIGUSR1);
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
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    return (act);
}

/*void    print_buff_and_nl(void)
{
    ft_printf("%s\n", &(buff_server[0]));
	ft_bzero(&(buff_server[0]), 50);
    return ;
}

void    check_is_buff_full(void)
{
    if (ft_strlen(&(buff_server[0])) == 49)
    {
        ft_printf("%s", &(buff_server[0]));
        ft_bzero(&(buff_server[0]), 50);
    }
    return ;
}

void    add_let_to_buff(char let)
{
    int ind;

    ind = 0;
    while (buff_server[ind])
        ind++;
    buff_server[ind] = let;
    return ;
}*/
