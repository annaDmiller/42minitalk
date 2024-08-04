#include "header_server.h"

char    buff_server[50];

int main(void)
{
    struct sigaction    act;
    unsigned int        check;

    check = 0;
    act = init_sig_logic();
    ft_bzero(&(buff_server[0]), 50);
    ft_printf("%i\n", getpid());
    while(check >= 0)
    {
        check++;
    }
    return (0);
}
