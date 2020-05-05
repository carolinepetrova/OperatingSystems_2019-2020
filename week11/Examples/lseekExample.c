#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	int fd1 = open(argv[1], O_RDONLY);

	int pos = lseek(fd1, 2, SEEK_SET);

	int pos2 = lseek(fd1, 0, SEEK_CUR); // current position

	char tmp[4] = {0};
	sprintf(tmp, "%d", pos2);                    //print to buffer 
	write(1, "Cursor is at: ", sizeof("Cursor is at: "));
    write(1, tmp, sizeof(tmp));

	int pos3 = lseek(fd1, 0, SEEK_END); // size of file in bytes
	char tmp2[4] = {0};
	sprintf(tmp2, "%d", pos3);               //print to buffer 
	write(1, "\nSize of file is ", sizeof("\nSize of file is "));
	write(1, tmp2, sizeof(tmp2));
	close(fd1);

	return 0;
	}