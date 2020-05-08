#include <sys/types.h>  
#include <wait.h>
#include <stdio.h> 
#include <sys/types.h>  
#include <unistd.h>  

/* IDEA:
Child process is being substituted by the exec command but the 
parent process can still execute the for loop. Thus we can execute the 
parameters successively. On every iteration the for loop spawns a new child and waits for it to finish. 
The child does it's work and finishes (dies :D) while the parent process is still alive.
*/

int main(int argc, char * argv[]) {
	int i;
	for(i = 1; i < argc; i++) {
		int pid = fork();
		int status = 0;
		if(pid == -1) {
			perror("fork error");
			exit(-1);
		}
		else if (pid > 0) {
			wait(&status);
			printf("Process %s with pid=%d exited with status %d\n", argv[i],pid, status);
		}
		else {
			execlp(argv[i], argv[i],NULL);
			perror("exec error");
			exit(-1);
		}
	}
	return 0;
}