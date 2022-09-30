#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1,manejadorSenyal);
    printf("PID: %d\n", getpid());
    sleep(20);
    return 0;
}

void manejadorSenyal(int numSenyal){
    printf("He recibido una señal número: %d",numSenyal);
}