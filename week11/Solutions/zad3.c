#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

/*
Чете последователност от символи от файл, чието име е подадено като първи параметър. 
Извежда ги на стандартния изход. 
Първите 3 символа от всеки ред добавя след края на файл, чието име е подадено като втори параметър.
*/

int main(int argc, char * argv[]) {
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_CREAT|O_APPEND|O_WRONLY, 0644);
    if(fd1  == -1) {
        perror("Error opening file 1");
        exit(-1);
    }
    if(fd2  == -1) {
        perror("Error opening file 2");
        exit(-1);
    }
    char buff[1];
    int byteCount = 0;
    while(read(fd1,buff,1)>0) {
        write(1,buff,1);
        if(byteCount <3) {
            ++byteCount;
            write(fd2, buff, 1);
        }
        else {
        if(buff[0] == '\n') {
            byteCount = 0;
        }
        }
    }
    return 0;
}
