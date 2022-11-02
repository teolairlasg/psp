#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t padre, hijo1, hijo2;
    padre = getpid();
    hijo1 = fork();
    if (hijo1 == -1)
    {
        printf("Error en el fork!\n");
        exit(-1);
    }
    else if (hijo1 == 0)
    {
        printf("Soy el hijo1 (PID:%d).\n", getpid());
        sleep(1);
    }
    else
    {
        printf("Soy el padre (PID: %d), mi hijo1 (PID:%d) ha sido creado.\n", padre, hijo1);
        hijo2 = fork();
        if (hijo2 == -1)
        {
            printf("Error en el fork!\n");
            exit(-1);
        }
        else if (hijo2 == 0)
        {
            printf("Soy el hijo2 (PID:%d).\n", getpid());
        }
        else
        {
            printf("Soy el padre (PID: %d), mi hijo2 (PID:%d) ha sido creado.\n", padre, hijo2);
            int estado;
            pid_t hijoFinalizado;
            for (int i = 0; i < 2; i++)
            {
                hijoFinalizado = wait(&estado);
                printf("Un hijo (PID: %d) ha finalizado con estado: %d.\n", hijoFinalizado, WEXITSTATUS(estado));
            }
        }
    }
    printf("Hola\n");
    return 0;
}
