#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("演示fork函数的使用...\n");

	fork();
	printf("fork函数执行后...\n");

	return 0;
}
