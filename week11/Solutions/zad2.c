#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
int fd1, buff[1];
if ((fd1 = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
	perror(“open”); exit(-1);
}
while(read(0, buff, 1) > 0) {
	write(fd1, buff, 1);
if (buff[0] == '\t') {
	write(2, “>>>”, 3);
} 
else {
	write(2, buff, 1);
}
}
close(fd1);
return 0;
}
