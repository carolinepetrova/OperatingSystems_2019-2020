#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1],O_RDONLY);
  if(fd1 == -1) {
    perror("unexpected error")
    exit(-1)
  }
  int fd2 = open(argv[2],O_CREAT|O_TRUNC|O_WRONLY), 0777);
  if(fd2 == -1) {
    printf("unexpected error");
    return 1;
  }
  char byteBuff[1];
  while(read(fd1, byteBuff, 1) > 0) {
    write(fd2,byteBuff,1);
  }
  remove(argv[1]);
  close(fd1);
  close(fd2);
  return 0;
}
