#include "header_server.h"

int main(void)
{
    struct sigaction    act;
    unsigned int        check;

    check = 0;
    act = init_sig_logic();
    ft_printf("%i\n", getpid());
    while(check == 0)
    {
        ft_putstr_fd("Waiting for signals...", 1);
        if (!sleep(60))
            exit(1);
    }
    return (0);
}
