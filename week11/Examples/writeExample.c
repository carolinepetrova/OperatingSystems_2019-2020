#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main() {
	int fd1 = open("file2.txt", O_WRONLY|O_CREAT, 0777);
	write(fd1, "Hello ", 6);
	write(fd1, "something", 9);
	close(fd1);
	return 0;
}