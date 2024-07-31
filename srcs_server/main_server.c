#include "header_server.h"

int main(void)
{
    pid_t   PID_num;

    PID_num = getgid();
    ft_printf("%i\n", (int) PID_num);
    pause();
    return (0);
}