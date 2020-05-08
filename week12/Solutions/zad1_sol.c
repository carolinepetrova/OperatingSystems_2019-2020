#include <sys/types.h>  
#include <wait.h>
#include <stdio.h> 
#include <sys/types.h>  
#include <unistd.h>  

int main(int argc, char * argv[]) {
	int pid = fork();
	if(pid == -1) {
		perror("fork error");
		exit(-1);
	}
	else if(pid > 0) {
		int status = 0;
		wait(&status);
		printf("%d", status);
		if(status == 0)
			printf("Command name %s\n", argv[1]);
	}
	else {
		if(execlp(argv[1], argv[1], NULL) == -1) {
			perror("exec error");
			exit(-1);
		}
	}
	return 0;
}