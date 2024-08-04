#include "header_server.h"

void    hdl(int sig)
{
    static int  bit_num;
    static int  num_let;
    int         bit;

    if (sig == SIGUSR1)
        bit = 1;
    else
        bit = 0;
    num_let = (num_let << 1) ^ bit;
    bit_num++;
    if (bit_num == 8)
    {
        bit_num = 0;
        if (num_let == 0)
            return (print_buff_and_nl());
        check_is_buff_full();
        add_let_to_buff(num_let);
        num_let = 0;
    }
    return ;
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

void    print_buff_and_nl(void)
{
    ft_printf("%s\n", &(buff[0]));
    return ;
}

void    check_is_buff_full(void)
{
    if (ft_strlen(&(buff[0])) == 1024)
    {
        ft_printf("%s", &(buff[0]));
        ft_bzero(&(buff[0]), 0);
    }
    return ;
}

void    add_let_to_buff(char let)
{
    int ind;

    ind = 0;
    while (buff[ind])
        ind++;
    buff[ind] = let;
    return ;
}