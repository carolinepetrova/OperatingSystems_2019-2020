#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main() {
	char buff1[4];
	char buff2[4];
	int fd1 = open("file.txt", O_RDONLY);
	int bytesRead1 = read(fd1, buff1, 2);
	int bytesRead2 = read(fd1, buff2, 4);
	write(1, "buff1: ", 7);
	write(1, buff1, 2);
	write(1, "\nbuff2: ", 8);
	write(1, buff2, 4);
	return 0;
}