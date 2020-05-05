#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	int fd1 = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0777);
	int fd2 = open(argv[1],O_WRONLY);

	write(fd1, "hello\n", 6);
	write(fd2, "akula\n", 6);
	close(fd1);
	close(fd2);
	return 0;
	}