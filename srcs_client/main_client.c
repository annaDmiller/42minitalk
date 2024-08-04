#include "header_client.h"

void    send_letter(char let, int pid_server)
{
    int num_bit;
    int bit;

    num_bit = 0;
    while (num_bit < 8)
    {
        bit = (let >> (7 - num_bit)) & 1;
        if (bit == 1)
            kill(pid_server, SIGUSR2);
        else
            kill(pid_server, SIGUSR1);
        usleep(200);
        num_bit++;
    }
    return ;
}

void    sending_the_message(char *str, int pid_server)
{
    size_t  len_mes;
    size_t  num_let;

    len_mes = ft_strlen(str);
    num_let = 0;
    while (num_let <= len_mes)
    {
        send_letter(str[num_let], pid_server);
        num_let++;
    }
    return ;
}

int main(int argc, char **argv)
{
    int pid_server;

    if (argc != 3)
        return (ft_putstr_fd("Enter the PID of server and string to print\n", 2), 1);
    pid_server = ft_atoi(*(argv + 1));
    sending_the_message(*(argv + 2), pid_server);
    ft_printf("The message is sent\n");
    return (0);
}
