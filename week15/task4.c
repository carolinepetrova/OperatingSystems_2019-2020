#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
    int pid = fork();
    int status;
    if(pid == -1) {
        perror("fork error");
        exit(-1);
    }
    else if(pid > 1) {
        // parent
        wait(&status);
        if(status == 0) {
        execlp(argv[2], argv[2], NULL);
        }
    }
    else {
        //child
        if(execlp(argv[1], argv[1], NULL) == -1) {
            perror("exec errror");
            exit(-1);
        }
    }
    return 0;
}