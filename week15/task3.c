#include <sys/types.h>  
#include <sys/wait.h>
#include <stdio.h> 
#include <sys/types.h>  
#include <unistd.h>  

int main(int argc, char * argv[]) {
    int pid = fork();
    int status = 0;
    if(pid==0) {
        execv(argv[1], NULL);
    }
    else if (pid > 0) {
        wait(&status);
        if(status==0) {
            execv(argv[2],NULL);
        }
        else printf("first command was not executed");
    }
    else {
        perror("Couldn't fork");
        exit(-1);
    }
    return 0;
}