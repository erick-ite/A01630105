#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int pid = fork();
    if (pid==0) printf("Soy el hijo\n");
    else printf("soy el padre\n");

}