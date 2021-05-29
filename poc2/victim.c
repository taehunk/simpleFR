#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
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

  int a,b,res; 
  a=2; b=3;

  while(1){
    // Use libvul.so shared lib
    sleep(1);
    res = add(2,3);
//    res = sub(2,3);
    printf("%d + %d = %d\n", a, b, res);

    // Use libvul2.so shared lib
    sleep(1);
    res = mul(2,3);
//    res = div(2,3);
    printf("%d * %d = %d\n", a, b, res);
  }

  return 0;
}


