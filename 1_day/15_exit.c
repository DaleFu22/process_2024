#include <stdio.h>
#include <stdlib.h>

void fun1(void)
{
	printf("fun1:我真的退出了\n");
}

void fun2(void)
{
	printf("fun2:我要退出了\n");
}

void fun3(void)
{
	printf("fun3:退出了吗？\n");
}

int main(void)
{
	atexit(fun1);
	atexit(fun2);
	atexit(fun3);

	printf("演示exit函数退出时会执行退出处理函数以及清理IO缓冲\n");
	printf("hello world");

	exit(1);
}

