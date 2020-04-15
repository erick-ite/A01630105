#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void proccesSignal(int s){
    printf("Recibí segnal %d\n",s);
}

int main(){
    signal(10,proccesSignal);
    while(1){
        sleep(3);
        printf("trabajando\n");
    }

}