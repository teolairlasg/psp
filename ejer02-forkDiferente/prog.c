#include <stdio.h>   // PRINTF
#include <unistd.h>  // FORK, SLEEP, wait
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait

int main(int argc, char const *argv[])
{
    pid_t numPid;
    int num = 12;
    numPid = fork();
    if(numPid == 0){ //proceso hijo devolverá cierto y entrará en el if
        printf("Soy el hijo mi pid es: %d\n", getpid());
        num = num+3;
        sleep(1); //el hijo espera un segundo
    }else{
        printf("Soy el padre, mi pid es: %d\n", getpid());
        int estado; //declaro un entero donde el wait guardará información sobre el retorno.
        pid_t pidFinalizado=wait(&estado);
        printf("El hijo con PID: %d finalizó con estado %d, el 'valor' de estado es: %d\n", 
                pidFinalizado,WEXITSTATUS(estado),estado);
        //el 'valor' de estado no tiene ningún sentido práctico, ya que en todos los bits de ese entero el wait codifica diferentes datos que nos dan información sobre la finalización de ese proceso. 
        //Más info en 'man wait'
                
        sleep(1);
    }
    printf("Hola, num es: %d\n",num);


    return 23;
}
