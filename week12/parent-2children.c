#include <sys/types.h>
#include <stdio.h> 
#include <sys/types.h>  
#include <unistd.h>  

/*

        Parent
       /     \
	Child1	Child2
				
*/

int main() {
	int status = 0; 
	// creates the first child 
	int pid = fork();
	// we isolate code which will be done only from the parent
	// so we create only one child
	if(pid>0) {
		int pid2 = fork();
	}
	// print 3 times hello 
	printf("Hello!!!\n");

	return 0;
}