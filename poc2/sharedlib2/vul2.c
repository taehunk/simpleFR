#include <stdio.h>

int mul(int a, int b)
{
	printf("mul() is called...\n");
	return a*b;
}

int div(int a, int b)
{
	printf("div() is called...\n");
	return (int)(a/b);
}
