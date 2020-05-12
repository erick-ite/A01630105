#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
 
 
#define MAX_LINE 80
#define MAX_NUM_ARGS 10
 
size_t string_parser(const char *input, char *word_array[]) {
  size_t n = 0;
  while (*input) {
    while (isspace((unsigned char)*input))
      ++input;
    if (*input) {
      word_array[n++] = (char *)input;
      while (*input && !isspace((unsigned char)*input))
        ++input;
    }
  }
 
  return n;
}
 
int main(void) {
  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
  char line[MAX_LINE + 1];
  int should_run = 1;
 
  int i;
 
//   while (should_run) {
//     printf("mish> ");
//     fgets(line,MAX_LINE,stdin);
//     line[strcspn(line, "\n")] = '\0';
//     // Separamos la línea en palabras separadas por espacio
//     // y las guardamos en args
//     i = string_parser(line,args); // i contiene el número de argumentos
//     //printf("%d, %s %s\n", i, args[1],line); // Es solo para pruebas borrar cuando esté listo
    
 
 
//     /**
//     (1) Crear un proceso hijo
//     (2) El hijo debe ejecutar execvp para ejecutar al comando tecleado
//     (3) Si el programa no existe debe imprimir programa no encontrado
//     (4) El proceso padre debe esperar a que el hijo termine, checar funcion wait
//     (5) Debe ejecutar comandos como ls -l /etc o ps -fea
//     (6) Cuando se teclee exit deberá terminar
//     **/
 
//     //checa si el argumento[0] es exit y si es, salimos
//     if( (strcmp(args[0], "exit")) == 0 ){
//         break;
//     }
    
//     //crea proceso hijo
//     int child;
//     child = fork();
//     if(child == 0){
//         //ejecuta execvp (este no regresa nada amenos que sea un error), en caso de error (-1) imprime programa no encontrado
//         if( execvp( args[0],args) < 0 ){
//             printf("programa no encontrado\n");
//             break;
//         }
//         //wait(NULL) hace que el proceso padre espera al proceso hijo
//         wait(NULL);
//     }
    
    
 
    
//     fflush(stdout);
//     fflush(stdin);
//     line[0] = '\0';
//   }
 
    while (should_run) {
    printf("mish> ");
    fgets(line,MAX_LINE,stdin);
    line[strcspn(line, "\n")] = '\0';
    // Separamos la línea en palabras separadas por espacio
    // y las guardamos en args
    i = string_parser(line,args); // i contiene el número de argumentos    
    if(strcmp(line , "exit") == 0){         
        should_run = 0;         
        printf("EXIT\n");        
    }else{       
        pid_t fork_pid = fork();     
        if (fork_pid == 0) {            
            if(execvp(args[0],args)<0)             
                printf("Programa no encontrado\n");          
                break;                  }       
            else {           
                wait(NULL);         
        }    
    }
    }
 
 
  return 0;
}

