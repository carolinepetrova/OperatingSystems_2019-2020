#include <sys/types.h>
#include <stdio.h> 
#include <sys/types.h>  
#include <unistd.h>  

/*

        Parent
       /      \
    Child2   Child1
				\
				Child3
*/

int main() {
	int status = 0; 
	// creates the first child 
	int pid = fork();
	/* as we created the first child everything from here is executed 
	by the parent and the child so the parent will create another child
	and the first child of the parent will create it's own child too
	*/
	int pid2 = fork();
	// print 4 times hello 
	printf("Hello!!!\n");

	return 0;
}