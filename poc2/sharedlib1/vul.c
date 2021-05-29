#include <stdio.h>

char __attribute__((aligned(4096))) mem[256 * 4096];

int add(int a, int b)
{
	printf("add() is called...\n");
	return a+b;
}

int sub(int a, int b)
{
	printf("sub() is called...\n");
	return a-b;
}
