#include "header_client.h"

void    error_hdl(char *cause)
{
    if (!ft_strncmp(cause, "sigaction", 10))
    {
        write(2, "Sigaction error.\n", 17);
        exit (EXIT_FAILURE);
    }
    if (!ft_strncmp(cause, "pid", 4))
    {
        write(2, "PID is beyond the limits.\n", 26);
        exit (EXIT_FAILURE);
    }
    if (!ft_strncmp(cause, "kill", 5))
    {
        write(2, "Kill error: incorrect signal, PID or acces.\n", 44);
        exit (EXIT_FAILURE);
    }
    write(2, "Unexpected error.\n", 18);
    exit (EXIT_FAILURE);
}