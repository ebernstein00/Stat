#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

struct stat buffer;
int status;

int main(){
  status = stat("/dev/random", &buffer);
  if (status < 0){
    printf("Error #%d: %s\n", errno, strerror(errno));
  }
  printf("Information for selected file:\n");
  printf("File Size:\t\t%d bytes\n", buffer.st_size);
  printf("File mode:\t\t%o\n", buffer.st_mode);
  printf("Last access time:\t\t%s\n", ctime(&buffer.atime));
}
