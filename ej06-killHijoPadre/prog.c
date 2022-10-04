#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void tratarSenyal(int codSenyal);

int main(int argc, char const *argv[])
{

    pid_t p;

    p = fork();

    if (p == 0)
    {
        // Soy el hijo
        printf("[HIJO]: En 1 seg. le envío una señal al padre\n");
        sleep(1);
        kill(getppid(), SIGUSR1);
        printf("[HIJO]: Señal enviada, en un segundo terminaré.\n");
        sleep(1);
    }
    else
    {
        // Soy el padre
        signal(SIGUSR1, tratarSenyal);
        printf("[PADRE]: Me quedo esperando señal del hijo.\n");
        pause();
        int estado;
        printf("[PADRE]: Me quedo esperando la finalización del hijo.\n");
        p=wait(&estado);
        printf("[PADRE]: El hijo %d ha terminado con estado %d\n",
         p, WEXITSTATUS(estado));
    }
    return 0;
}

void tratarSenyal(int codSenyal){
    printf("[PADRE]: He recibido una señal.\n");

}