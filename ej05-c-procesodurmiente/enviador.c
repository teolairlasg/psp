#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr,"\nError, el programa debe tener un parámetro.\n\n");
        fprintf(stdout, "Uso del programa: \n\t %s <num_pid>\n\n",argv[0]);
        exit(-1);
    }
    
    pid_t pidParametro = atoi(argv[1]);

    kill(pidParametro, SIGUSR1);

    return 0;
}
