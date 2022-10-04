#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //execl("/usr/bin/firefox", "firefox", "https://educa.aragon.es", NULL);
    char* v[]={"firefox", "https://educa.aragon.es", NULL};
    execv("/usr/bin/firefox",v);
    
    //system("ls -l > ls.txt");

    return 0;
}
