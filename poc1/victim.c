#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>
#include "../cacheutils.h"


int main(int argc, char **argv) {

  size_t threshold;
  size_t start, end;

  if(argc < 2){
	  printf("Usage: %s [*.txt]\n", argv[0]);
  } 
  
  int fd = open(argv[1], O_RDONLY); 
  assert(fd);

  unsigned char *addr = (unsigned char *)mmap(0, sysconf(_SC_PAGE_SIZE), PROT_READ, MAP_PRIVATE, fd, 0);
  if(addr == (void *) -1)
	  return 0;

  for(;;){
    sleep(1);
    maccess(addr);
    printf("Access a target file\n");

  }

  return 0;
}
