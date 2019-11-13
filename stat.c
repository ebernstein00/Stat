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
  status = stat("file.txt", &buffer);
  if (status < 0){
    printf("Error #%d: %s\n", errno, strerror(errno));
  }
  printf("Information for selected file:\n");
  printf("File Size:\t\t%d\n", buffer.st_size);
  printf("File mode:\t\t%o\n", buffer.st_mode);
  printf("Last access time:\t%s\n", ctime(&buffer.st_atime));

  //KB, MB, GB
  int size = buffer.st_size;
  char holder[100];
  printf("File Size:\t\t%d B\n", size);
  if(size >= 1024){
  	sprintf(holder, "File Size:\t\t%d KB\n", size / 1024);
  	size /= 1024;
  }
  if(size >= 1024){
  	sprintf(holder, "File Size:\t\t%d MB\n", size / 1024);
  	size /= 1024;
  }
  if(size >= 1024){
  	sprintf(holder, "File Size:\t\t%d GB\n", size / 1024);
  	size /= 1024;
  }
}
