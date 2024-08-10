#include "header_server.h"

volatile t_state *point_state;

int main(void)
{
    struct sigaction    act;
    t_state             state;

    init_state(&state);
    act = init_sig_logic();
    ft_printf("%i\n", getpid());
    while(1)
    {
        if (point_state->bit_num == 0 && point_state->client_pid != 0)
        {
            if (point_state->check_end_mess == 1)
            {
                ft_printf("\n");
                point_state->check_end_mess = 0;
                kill(point_state->client_pid, SIGUSR2);
            }
            else if (point_state->let != 0)
                ft_printf("%c", point_state->let);
            point_state->let = 0;
        }
        if (point_state->client_pid != 0)
            kill(point_state->client_pid, SIGUSR1);
        usleep(100);
    }
    return (0);
}

void    init_state(t_state *state)
{
    state->let = 0;
    state->bit_num = 0;
    state->client_pid = 0;
    state->check_end_mess = 0;
    point_state = state;
    return ;
}
