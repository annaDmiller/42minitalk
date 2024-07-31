#include "header_client.h"

int main(int argc, char **argv)
{
    int PID_server;

    if (argc != 3)
        return (ft_putstr_fd("Enter the PID of server and string to print\n", 2), 1);
    PID_server = ft_atoi(*argv + 1);
    kill(PID_server, SIGINT);
    return (0);
}