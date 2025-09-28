#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(void){
  int fd = open("stdio4.c", O_RDONLY);
  printf("Open file descriptor: %d\n", fd);

  void *mem = mmap(NULL, 100, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
  printf("File mapped at: %p\n", mem);
  printf("%c", ((char*)mem)[1]);

  char *s = mem;
  for (int j = 0; j<10; j++){
    printf("s[%d] = %c\n", j , s[j]);
  }
  return 0;
}

