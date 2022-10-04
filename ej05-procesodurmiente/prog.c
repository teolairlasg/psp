#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1,manejadorSenyal);
    signal(SIGUSR2,manejadorSenyal);
    printf("PID: %d\n", getpid());
    pause();
    printf("PID: %d\n", getpid());
    return 0;
}

void manejadorSenyal(int numSenyal){
    printf("He recibido una señal número: %d\n",numSenyal);
}